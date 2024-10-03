#include <iostream>

#include "code/loggerAPIs/eventLogger.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    eventLogger logger;
    logger.logEvent("your mom");
    return 0;
}

