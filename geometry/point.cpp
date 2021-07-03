#include<bits/stdc++.h>
using namespace std;

namespace geometry {
  constexpr double EPS = 1e-8;

  bool equals(double a, double b) {
    return fabs(a - b) < EPS;
  }

  struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator+(point p) { return point(x + p.x, y + p.y); }
    point operator-(point p) { return point(x - p.x, y - p.y); }
    point operator*(double k) { return point(x * k, y * k); }
    point operator/(double k) { return point(x / k, y / k); }
    point &operator+=(point p) { x += p.x; y += p.y; return *this; }
    point &operator-=(point p) { x -= p.x; y -= p.y; return *this; }
    point &operator*=(double k) { x *= k; y *= k; return *this; }
    point &operator/=(double k) { x /= k; y /= k; return *this; }
    point operator-() const { return point(-x, -y); }

    bool operator==(const point &p) const { return (fabs(x - p.x) < EPS) && (fabs(x - p.y) < EPS); }
    bool equals(const point &p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
    bool operator<(const point &p) const { return x == p.x ? y < p.y : x < p.x; }
    double euclid() { return sqrt(x * x + y * y); }
    double euclid(point p) { p.x -= x, p.y -= y; return p.euclid(); }

    double radian() { return atan2(y, x) + (y < 0 ? 2 * M_PI : 0.0); } // 0~2π
    double radian(point p) { p.x -= x, p.y -= y; return p.radian(); }
    double theta() { return radian() * 180.0 / M_PI; }
    double theta(point p) { return radian(p) * 180.0 / M_PI; }

    friend istream &operator>>(istream &is, point &p) { is >> p.x >> p.y; return is; }
    friend ostream &operator<<(ostream &os, const point &p) { os << p.x << ' ' << p.y; return os; }
  };

  bool comp_x(point a, point b) { return fabs(a.x - b.x) < EPS ? a.y < b.y : a.x < b.x; }
  bool comp_y(point a, point b) { return fabs(a.y - b.y) < EPS ? a.x < b.x : a.y < b.y; }
  double cross(point a, point b) { return a.x * b.y - a.y * b.x; }

  // rotate_clockwise
  point rot_cw(point origin, double radian, point p) {
    p -= origin;
    point res = point(p.x * cos(radian) + p.y * sin(radian),
                      -p.x * sin(radian) + p.y * cos(radian));
    res += origin;
    return res;
  }

  // rotate_counterclockwise
  point rot_ccw(point origin, double radian, point p) {
    p -= origin;
    point res = point(p.x * cos(radian) + p.y * -sin(radian),
                      p.x * sin(radian) + p.y * cos(radian));
    res += origin;
    return res;
  }

  // 線分abをm:nに内分する点
  point internal_division(point a, point b, double m, double n) {
    if ( equals(m + n, 0.0) ) return point(0, 0);
    return point((a.x * n + b.x * m) / (m + n), (a.y * n + b.y * m) / (m + n));
  }

  // 線分abをm:nに外分する点
  point external_division(point a, point b, double m, double n) {
    if ( equals(m - n, 0.0) ) return point(0, 0);
    return point((-n * a.x + m * b.x) / (m - n), (-n * a.y + m * b.y) / (m - n));
  }
}
using namespace geometry;

int main(){

}