//
// Created by apumu on 10/2/2024.
//

#include "eventLogger.hpp"
#include <iostream>

eventLogger::eventLogger(): tempType(0) {}


void eventLogger::logEvent(std::string event) {
    std::cout << "Event: " << event;
}
eventLogger::~eventLogger() {

}