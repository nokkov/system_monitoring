#include <iostream>
#include "system-data/cpu-usage.h"


int main() {
    std::cout << "CPU Usage: " << getCPUUsage() << "%" << std::endl;

    timeData data = getUpTime();

    // Assign some values to the fields
    data.days = std::chrono::duration<long, std::ratio<86400>>(3);
    data.hours = std::chrono::duration<long, std::ratio<3600>>(12);
    data.minutes = std::chrono::duration<long, std::ratio<60>>(30);
    data.seconds = std::chrono::duration<long>(45);

    // Output the values of the fields
    std::cout << "Days: " << data.days.count() << std::endl;
    std::cout << "Hours: " << data.hours.count() << std::endl;
    std::cout << "Minutes: " << data.minutes.count() << std::endl;
    std::cout << "Seconds: " << data.seconds.count() << std::endl;

    return 0;
}
