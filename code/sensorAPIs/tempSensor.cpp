//
// Created by apumu on 10/3/2024.
//

#include "tempSensor.hpp"

#include <random>

// creates and starts a thread for the run function
void tempSensor::start() {
    running = true;
    sensorThread = std::thread(&tempSensor::run, this);
}

// ends
void tempSensor::stop() {
    running = false;
    if(sensorThread.joinable()) {
        sensorThread.join();
    }
}
// return the current temp stored in
int tempSensor::getTemp() const {
    std::lock_guard<std::mutex> lock(m);
    return tempReading;
}

void tempSensor::run() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 100);

    while(running) {
        {
            std::lock_guard<std::mutex> lock(m);
            tempReading = distribution(generator);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}