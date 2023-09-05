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

//TODO fixme: uncorrect time
timeData getUpTime() {
    using namespace std::chrono;

    std::ifstream uptimeFile("/proc/uptime");
    double uptime;
    uptimeFile >> uptime;

    seconds sUptime = duration_cast<seconds>(duration<double>(uptime));
    std::chrono::seconds s {sUptime};
    auto days = duration_cast<std::chrono::days>(s);
    s -= days;

    auto hours = duration_cast<std::chrono::hours>(s);
    s -= hours;

    auto minutes = duration_cast<std::chrono::minutes>(s);
    s -= minutes;

    auto seconds = s;

    timeData time_data = {days, hours, minutes, seconds};
    return time_data;
}