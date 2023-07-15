---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/base.hpp
    title: math/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qiita.com/ageprocpp/items/7bda728d109c953ece3c
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\n#line 2 \"math/base.hpp\"\n\nnamespace\
    \ matumoto {\n  using namespace std;\n  using ll = long long;\n} // namespace\
    \ matumoto\n#line 4 \"math/matrix.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  class Matrix {\n    int row_,\
    \ column_;\n    vector<vector<T>> matrix_;\n\n  public:\n    Matrix() = default;\n\
    \    Matrix(const vector<vector<T>> &matrix): matrix_(matrix) {\n      if (matrix.empty())\
    \ {\n        row_ = 0;\n        column_ = 0;\n        return;\n      }\n\n   \
    \   row_ = matrix_.size();\n      column_ = matrix.at(0).size();\n\n      for\
    \ (const vector<T> &line: matrix) {\n        int col = line.size();\n        assert(col\
    \ == column_);\n      }\n    }\n\n    int row() const {\n      return row_;\n\
    \    }\n\n    int column() const {\n      return column_;\n    }\n\n    constexpr\
    \ Matrix pow(long long n) const {\n      assert(n >= 0);\n\n      Matrix x = /*\
    \ base = */ *this;\n      Matrix res(vector<vector<T>>(row_, vector<T>(column_,\
    \ /*product identity element=*/T(1))));\n\n      while (n) {\n        if (n &\
    \ 1) {\n          res *= x;\n        }\n        x *= x;\n        n >>= 1;\n  \
    \    }\n      return res;\n    }\n\n    vector<vector<T>> matrix() const {\n \
    \     return matrix_;\n    }\n\n    constexpr Matrix &operator+=(const Matrix\
    \ &rhs) {\n      assert(row_ == rhs.row_);\n      assert(column_ == rhs.column_);\n\
    \n      for (int i = 0; i < row_; i++) {\n        for (int j = 0; j < column_;\
    \ j++) {\n          matrix_.at(i).at(j) += rhs.matrix_.at(i).at(j);\n        }\n\
    \      }\n      return matrix_;\n    }\n\n    constexpr Matrix &operator-=(const\
    \ Matrix &rhs) {\n      assert(row_ == rhs.row_);\n      assert(column_ == rhs.column_);\n\
    \n      for (int i = 0; i < row_; i++) {\n        for (int j = 0; j < column_;\
    \ j++) {\n          matrix_.at(i).at(j) -= rhs.matrix_.at(i).at(j);\n        }\n\
    \      }\n      return matrix_;\n    }\n\n    constexpr Matrix &operator*=(const\
    \ Matrix &rhs) {\n      assert(column_ == rhs.row_);\n\n      vector<vector<T>>\
    \ prod(row_, vector<T>(rhs.column_, /*additive identity element=*/T(0)));\n\n\
    \      // https://qiita.com/ageprocpp/items/7bda728d109c953ece3c\n      for (int\
    \ i = 0; i < row_; i++) {\n        for (int k = 0; k < column_; k++) {\n     \
    \     for (int j = 0; j < rhs.column_; j++) {\n            prod.at(i).at(j) +=\
    \ matrix_.at(i).at(k) * rhs.matrix_.at(k).at(j);\n          }\n        }\n   \
    \   }\n\n      return matrix_ = prod;\n    }\n\n    const Matrix &operator*=(const\
    \ T &scalar) {\n      for (int i = 0; i < row_; i++) {\n        for (int j = 0;\
    \ j < column_; j++) {\n          matrix_.at(i).at(j) *= scalar;\n        }\n \
    \     }\n      return matrix_;\n    }\n\n    constexpr Matrix operator+() const\
    \ {\n      return *this;\n    }\n\n    constexpr Matrix operator-() const {\n\
    \      return Matrix(this->matrix_) - *this;\n    }\n\n    constexpr friend Matrix\
    \ operator+(const Matrix &lhs, const Matrix &rhs) {\n      return Matrix(lhs)\
    \ += rhs;\n    }\n\n    constexpr friend Matrix operator-(const Matrix &lhs, const\
    \ Matrix &rhs) {\n      return Matrix(lhs) -= rhs;\n    }\n\n    constexpr friend\
    \ Matrix operator*(const Matrix &lhs, const Matrix &rhs) {\n      return Matrix(lhs)\
    \ *= rhs;\n    }\n\n    constexpr friend bool operator==(const Matrix &lhs, const\
    \ Matrix &rhs) {\n      return lhs.matrix_ == rhs.matrix_;\n    }\n\n    constexpr\
    \ friend bool operator!=(const Matrix &lhs, const Matrix &rhs) {\n      return\
    \ lhs.matrix_ != rhs.matrix_;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const Matrix &rhs) {\n      for (int i = 0; i < rhs.row_; i++) {\n    \
    \    for (int j = 0; j < rhs.column_; j++) {\n          os << rhs.matrix_.at(i).at(j);\n\
    \          os << (j == rhs.column_ - 1 ? \"\\n\" : \" \");\n        }\n      }\n\
    \      return os;\n    }\n  };\n} // namespace matumoto\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \nnamespace matumoto {\n  template <typename T>\n  class Matrix {\n    int row_,\
    \ column_;\n    vector<vector<T>> matrix_;\n\n  public:\n    Matrix() = default;\n\
    \    Matrix(const vector<vector<T>> &matrix): matrix_(matrix) {\n      if (matrix.empty())\
    \ {\n        row_ = 0;\n        column_ = 0;\n        return;\n      }\n\n   \
    \   row_ = matrix_.size();\n      column_ = matrix.at(0).size();\n\n      for\
    \ (const vector<T> &line: matrix) {\n        int col = line.size();\n        assert(col\
    \ == column_);\n      }\n    }\n\n    int row() const {\n      return row_;\n\
    \    }\n\n    int column() const {\n      return column_;\n    }\n\n    constexpr\
    \ Matrix pow(long long n) const {\n      assert(n >= 0);\n\n      Matrix x = /*\
    \ base = */ *this;\n      Matrix res(vector<vector<T>>(row_, vector<T>(column_,\
    \ /*product identity element=*/T(1))));\n\n      while (n) {\n        if (n &\
    \ 1) {\n          res *= x;\n        }\n        x *= x;\n        n >>= 1;\n  \
    \    }\n      return res;\n    }\n\n    vector<vector<T>> matrix() const {\n \
    \     return matrix_;\n    }\n\n    constexpr Matrix &operator+=(const Matrix\
    \ &rhs) {\n      assert(row_ == rhs.row_);\n      assert(column_ == rhs.column_);\n\
    \n      for (int i = 0; i < row_; i++) {\n        for (int j = 0; j < column_;\
    \ j++) {\n          matrix_.at(i).at(j) += rhs.matrix_.at(i).at(j);\n        }\n\
    \      }\n      return matrix_;\n    }\n\n    constexpr Matrix &operator-=(const\
    \ Matrix &rhs) {\n      assert(row_ == rhs.row_);\n      assert(column_ == rhs.column_);\n\
    \n      for (int i = 0; i < row_; i++) {\n        for (int j = 0; j < column_;\
    \ j++) {\n          matrix_.at(i).at(j) -= rhs.matrix_.at(i).at(j);\n        }\n\
    \      }\n      return matrix_;\n    }\n\n    constexpr Matrix &operator*=(const\
    \ Matrix &rhs) {\n      assert(column_ == rhs.row_);\n\n      vector<vector<T>>\
    \ prod(row_, vector<T>(rhs.column_, /*additive identity element=*/T(0)));\n\n\
    \      // https://qiita.com/ageprocpp/items/7bda728d109c953ece3c\n      for (int\
    \ i = 0; i < row_; i++) {\n        for (int k = 0; k < column_; k++) {\n     \
    \     for (int j = 0; j < rhs.column_; j++) {\n            prod.at(i).at(j) +=\
    \ matrix_.at(i).at(k) * rhs.matrix_.at(k).at(j);\n          }\n        }\n   \
    \   }\n\n      return matrix_ = prod;\n    }\n\n    const Matrix &operator*=(const\
    \ T &scalar) {\n      for (int i = 0; i < row_; i++) {\n        for (int j = 0;\
    \ j < column_; j++) {\n          matrix_.at(i).at(j) *= scalar;\n        }\n \
    \     }\n      return matrix_;\n    }\n\n    constexpr Matrix operator+() const\
    \ {\n      return *this;\n    }\n\n    constexpr Matrix operator-() const {\n\
    \      return Matrix(this->matrix_) - *this;\n    }\n\n    constexpr friend Matrix\
    \ operator+(const Matrix &lhs, const Matrix &rhs) {\n      return Matrix(lhs)\
    \ += rhs;\n    }\n\n    constexpr friend Matrix operator-(const Matrix &lhs, const\
    \ Matrix &rhs) {\n      return Matrix(lhs) -= rhs;\n    }\n\n    constexpr friend\
    \ Matrix operator*(const Matrix &lhs, const Matrix &rhs) {\n      return Matrix(lhs)\
    \ *= rhs;\n    }\n\n    constexpr friend bool operator==(const Matrix &lhs, const\
    \ Matrix &rhs) {\n      return lhs.matrix_ == rhs.matrix_;\n    }\n\n    constexpr\
    \ friend bool operator!=(const Matrix &lhs, const Matrix &rhs) {\n      return\
    \ lhs.matrix_ != rhs.matrix_;\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, const Matrix &rhs) {\n      for (int i = 0; i < rhs.row_; i++) {\n    \
    \    for (int j = 0; j < rhs.column_; j++) {\n          os << rhs.matrix_.at(i).at(j);\n\
    \          os << (j == rhs.column_ - 1 ? \"\\n\" : \" \");\n        }\n      }\n\
    \      return os;\n    }\n  };\n} // namespace matumoto\n"
  dependsOn:
  - math/base.hpp
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-07-08 14:12:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
