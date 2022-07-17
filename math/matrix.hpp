#pragma once

#include "./base.hpp"

#include <cassert>
#include <vector>

namespace math_library {
  template <typename T>
  class Matrix {
    int row_, column_;
    vector<vector<T>> matrix_;

  public:
    Matrix() = default;
    Matrix(const vector<vector<T>> &matrix): matrix_(matrix) {
      if (matrix.empty()) {
        row_ = 0;
        column_ = 0;
        return;
      }

      row_ = matrix_.size();
      column_ = matrix.at(0).size();

      for (const vector<T> &line: matrix) {
        int col = line.size();
        assert(col == column_);
      }
    }

    int row() const {
      return row_;
    }

    int column() const {
      return column_;
    }

    constexpr Matrix pow(long long n) const {
      assert(n >= 0);

      Matrix x = /* base = */ *this;
      Matrix res(vector<vector<T>>(row_, vector<T>(column_, /*product identity element=*/T(1))));

      while (n) {
        if (n & 1) {
          res *= x;
        }
        x *= x;
        n >>= 1;
      }
      return res;
    }

    vector<vector<T>> matrix() const {
      return matrix_;
    }

    constexpr Matrix &operator+=(const Matrix &rhs) {
      assert(row_ == rhs.row_);
      assert(column_ == rhs.column_);

      for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_; j++) {
          matrix_.at(i).at(j) += rhs.matrix_.at(i).at(j);
        }
      }
      return matrix_;
    }

    constexpr Matrix &operator-=(const Matrix &rhs) {
      assert(row_ == rhs.row_);
      assert(column_ == rhs.column_);

      for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_; j++) {
          matrix_.at(i).at(j) -= rhs.matrix_.at(i).at(j);
        }
      }
      return matrix_;
    }

    constexpr Matrix &operator*=(const Matrix &rhs) {
      assert(column_ == rhs.row_);

      vector<vector<T>> prod(row_, vector<T>(rhs.column_, /*additive identity element=*/T(0)));

      // https://qiita.com/ageprocpp/items/7bda728d109c953ece3c
      for (int i = 0; i < row_; i++) {
        for (int k = 0; k < column_; k++) {
          for (int j = 0; j < rhs.column_; j++) {
            prod.at(i).at(j) += matrix_.at(i).at(k) * rhs.matrix_.at(k).at(j);
          }
        }
      }

      return matrix_ = prod;
    }

    const Matrix &operator*=(const T &scalar) {
      for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_; j++) {
          matrix_.at(i).at(j) *= scalar;
        }
      }
      return matrix_;
    }

    constexpr Matrix operator+() const {
      return *this;
    }

    constexpr Matrix operator-() const {
      return Matrix(this->matrix_) - *this;
    }

    constexpr friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
      return Matrix(lhs) += rhs;
    }

    constexpr friend Matrix operator-(const Matrix &lhs, const Matrix &rhs) {
      return Matrix(lhs) -= rhs;
    }

    constexpr friend Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
      return Matrix(lhs) *= rhs;
    }

    constexpr friend bool operator==(const Matrix &lhs, const Matrix &rhs) {
      return lhs.matrix_ == rhs.matrix_;
    }

    constexpr friend bool operator!=(const Matrix &lhs, const Matrix &rhs) {
      return lhs.matrix_ != rhs.matrix_;
    }

    friend ostream &operator<<(ostream &os, const Matrix &rhs) {
      for (int i = 0; i < rhs.row_; i++) {
        for (int j = 0; j < rhs.column_; j++) {
          os << rhs.matrix_.at(i).at(j);
          os << (j == rhs.column_ - 1 ? "\n" : " ");
        }
      }
      return os;
    }
  };
} // namespace math_library
