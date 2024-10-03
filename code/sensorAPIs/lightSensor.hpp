//
// Created by apumu on 10/2/2024.
//
#ifndef LIGHTSENSOR_HPP
#define LIGHTSENSOR_HPP

#include <thread>
#include <atomic>
#include <mutex>

class LightSensor {
public:
    LightSensor();
    ~LightSensor();

    void start();
    void stop();
    int getReading() const;

private:
    void run();
    std::atomic<bool> running;
    std::thread sensorThread;
    mutable std::mutex dataMutex;
    int lightData;
};

#endif // LIGHTSENSOR_HPP