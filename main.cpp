#include <iostream>
#include "system-data/cpu-usage.h"


int main() {
    //test
    std::cout << "CPU Usage: " << getCPUUsage() << "%" << std::endl;

    timeData data = getUpTime();

    std::cout << "Days: " << data.days << std::endl;
    std::cout << "Hours: " << data.hours << std::endl;
    std::cout << "Minutes: " << data.minutes << std::endl;
    std::cout << "Seconds: " << data.seconds << std::endl;

    std::cout << "CPU Model: " << getCPUModelName() << std::endl;

    return 0;
}
