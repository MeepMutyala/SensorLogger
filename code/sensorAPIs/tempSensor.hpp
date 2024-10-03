//
// Created by apumu on 10/3/2024.
//

#ifndef TEMPSENSOR_HPP
#define TEMPSENSOR_HPP
#include <atomic>
#include <mutex>
#include <thread>


class tempSensor {
public:
    tempSensor();
    ~tempSensor();

    void start();
    void stop();
    int getTemp() const;

private:
    mutable std::mutex m;
    std::thread sensorThread;
    std::atomic<bool> running;
    void run();
    int tempReading;
};



#endif //TEMPSENSOR_HPP
