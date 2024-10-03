//
// Created by apumu on 10/2/2024.
//
#include "lightSensor.hpp"
#include <iostream>
#include <chrono>
#include <random>

//initialize lightsensor to false and lightdata to 0
LightSensor::LightSensor() : running(false), lightData(0) {}

// call stop on destruction
LightSensor::~LightSensor() {
    stop();
}

// this starts the light sensor by creating
// and starting a thread for the run function
void LightSensor::start() {
    running = true;
    sensorThread = std::thread(&LightSensor::run, this);
}

// sets running to false, so the loop in run() ends
void LightSensor::stop() {
    running = false;
    if (sensorThread.joinable()) {  //
        sensorThread.join();
    }
}

// whenever we call getReading(), the mutex we created
// (in header file) locks the shared data
int LightSensor::getReading() const {
    std::lock_guard<std::mutex> lock(dataMutex); // locks the current thread (getReading)
    return lightData;
} // when the mutex goes out of scope (end of this function run) it's released automatically

// generates a random value 0-100,
// while running, we lock our shared resource (the distribution generator value)
// read, assign it to lightData, then delay for a second,
// continuously assigning the new light value to lightData each second
void LightSensor::run() {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 100);

    while (running) {
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            lightData = distribution(generator);    // reads in a simulated(random) light value and assigns it to lightData
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); //delay by a second
    }
}