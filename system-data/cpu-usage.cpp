#include "cpu-usage.h"

std::vector<double> getCPUTimes() {
    std::ifstream statFile("/proc/stat");
    statFile.ignore(5); //ignore 'cpu  '

    std::vector<double> times;
    for (double time; statFile >> time; times.push_back(time));
    return times;
}

std::pair<double, double> getTimePair() {
    std::vector<double> times = getCPUTimes();
    double idleTime = times[3];
    double totalTime = std::accumulate(times.begin(), times.end(), 0);
    return std::make_pair(idleTime, totalTime);
}

double getCPUUsage() {
    std::pair<double, double> firstUsage = getTimePair();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::pair<double, double> secondUsage = getTimePair();

    double idleDelta = secondUsage.first - firstUsage.first;
    double totalDelta = secondUsage.second - firstUsage.second;
    double usage = 100 * (1.0 - (idleDelta / totalDelta));
    return usage;
}

timeData getUpTime() {
    std::ifstream uptimeFile("/proc/uptime");
    unsigned int uptime;
    uptimeFile >> uptime; //in seconds

    unsigned int days = uptime / 86400;
    uptime %= 86400;

    unsigned int hours = uptime / 3600;
    uptime %= 3600;

    unsigned int minutes = uptime / 60;
    uptime %= 60;

    unsigned int seconds = uptime;

    return {days, hours, minutes, seconds};
}