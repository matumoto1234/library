#pragma once

#include "./base.hpp"

#include <chrono>

namespace matumoto {
  struct Stopwatch {
    chrono::high_resolution_clock::time_point start;

    Stopwatch() {
      restart();
    }

    void restart() {
      start = chrono::high_resolution_clock::now();
    }

    chrono::milliseconds::rep elapsed() {
      auto end = chrono::high_resolution_clock::now();
      return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
  };
} // namespace matumoto