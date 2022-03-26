#pragma once

#include "./base.hpp"

#include <chrono>

namespace tools_library {
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
} // namespace tools_library