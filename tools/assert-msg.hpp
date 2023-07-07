#pragma once

#include "base.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

namespace matumoto {
#define assert_msg(expr, msg) (static_cast<bool>(expr) ? void(0) : assert_fail(__FILE__, __LINE__, #expr, msg))

  namespace {
    void assert_fail(const char *file, int line, const char expr_str[], string msg) {
      cerr << "File: " << file << "\n"
           << "Line: " << line << "\n"
           << "Assertion '" << expr_str << "' failed.\n"
           << "Message: " << msg << "\n";
      abort();
    }
  } // namespace
} // namespace matumoto
