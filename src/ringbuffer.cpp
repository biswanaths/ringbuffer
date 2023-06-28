#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

struct ringbuffer {
    std::vector<int> data_;
    alignas(64) std::atomic<size_t> readIdx_{0};
    alignas(64) std::atomic<size_t> writeIdx_{0};

    ringbuffer(size_t capacity): data_(capacity) {}
};
