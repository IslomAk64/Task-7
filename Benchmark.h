#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>

template <typename Duration = std::chrono::microseconds>
class Benchmark {
public:
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    Duration elapsed() const {
        return std::chrono::duration_cast<Duration>(std::chrono::high_resolution_clock::now() - startTime);
    }

private:
    std::chrono::high_resolution_clock::time_point startTime;
};

#endif // BENCHMARK_H