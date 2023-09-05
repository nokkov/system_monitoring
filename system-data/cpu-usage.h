#ifndef SYSTEM_MONITORING_CPU_USAGE_H
#define SYSTEM_MONITORING_CPU_USAGE_H
#include <fstream>
#include <numeric>
#include <chrono>
#include <sys/sysinfo.h>
#include <thread>

//TODO do typedef (?)

struct timeData {
    std::chrono::duration<long, std::ratio<86400>> days;
    std::chrono::duration<long, std::ratio<3600>> hours;
    std::chrono::duration<long, std::ratio<60>> minutes;
    std::chrono::duration<long> seconds;
};

double getCPUUsage();
timeData getUpTime();

#endif //SYSTEM_MONITORING_CPU_USAGE_H