#pragma once
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
public:
    void start() { 
        start_time = std::chrono::high_resolution_clock::now(); 
    }
    void stop() { 
        end_time = std::chrono::high_resolution_clock::now(); 
    }
    long long getMicroseconds() const {
        return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
};
