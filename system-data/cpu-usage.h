#ifndef SYSTEM_MONITORING_CPU_USAGE_H
#define SYSTEM_MONITORING_CPU_USAGE_H
#include <fstream>
#include <numeric>
#include <chrono>
#include <sys/sysinfo.h>
#include <thread>

//TODO do typedef (?)

struct timeData {
    unsigned int days;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

double getCPUUsage();
timeData getUpTime();

#endif //SYSTEM_MONITORING_CPU_USAGE_H