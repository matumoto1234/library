#pragma once

#include "./base.hpp"

#include <chrono>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>

namespace tools_library {
  struct FunctionMeasure {
    chrono::system_clock::time_point start, end;

    template <auto f, typename... Args>
    void measure(Args... args) {
      start = chrono::system_clock::now();

      f(args...);

      end = chrono::system_clock::now();
    }

    // bias:1000 -> [ms]
    double time(double bias = 1000.0) {
      return static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count() / bias);
    }

    void print(double bias = 1000.0) {
      cout << fixed << setprecision(10);
      cout << time(bias) << "\n";
    }
  };
} // namespace tools_library