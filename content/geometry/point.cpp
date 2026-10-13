#pragma once

#include <bits/stdc++.h>

template<typename T>
struct Point {
    T x = 179, y = 179;

    explicit Point(T x, T y): x(x), y(y) {}

    bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
    bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }

    Point operator+(Point a) const { return {a.x + x, a.y + y}; }
    Point operator-(Point) const { return {x - a.x, y - a.y}; }

    Point operator*(const T a) const { return {x * a, y * a}; }
    Point operator/(const T a) const { return {x / a, y / a}; }
    
    T dot(Point a) const { return a.x * x + a.y * y; }
    T cross(Point a) const { return x * a.y - a.x * y; }
    T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }

    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    Point unit() const { return *this/dist(); }
    Point perp() const { return Point(-y, x); }
    Point normal() const { return perp().unit(); }
    Point rotate(double a) const { return {x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)}; }
};

template <typename T>
istream &operator>>(istream &in, Point<T> &a) {
    in >> a.x >> a.y;
    return in;
}
template <typename T>
ostream &operator<<(ostream &out, Point<T> a) {
    out << a.x << " " << a.y;
    return out;
}

template <typename T> int sgn(T x) { return (x > 0) - (x < 0); }