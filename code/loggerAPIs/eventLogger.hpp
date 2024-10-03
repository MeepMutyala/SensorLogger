//
// Created by apumu on 10/2/2024.
//

#ifndef EVENTLOGGER_HPP
#define EVENTLOGGER_HPP
#include <atomic>
#include <mutex>
#include <string>


class eventLogger {
public:
    eventLogger();
    ~eventLogger();
    void logEvent(std::string event);

private:
    std::atomic<bool> tempType; //0 for fahrenheit, 1 for celsius
    mutable std::mutex mutex;

};

#endif //EVENTLOGGER_HPP
