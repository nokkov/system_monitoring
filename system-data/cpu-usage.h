#ifndef SYSTEM_MONITORING_CPU_USAGE_H
#define SYSTEM_MONITORING_CPU_USAGE_H
#include <fstream>
#include <numeric>
#include <chrono>
#include <sys/sysinfo.h>
#include <thread>
#include <boost/algorithm/string.hpp>

//TODO do typedef (?)

struct timeData {
    unsigned int days;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

double getCPUUsage() noexcept;
timeData getUpTime() noexcept;
std::string getCPUModelName() noexcept;

#endif //SYSTEM_MONITORING_CPU_USAGE_H