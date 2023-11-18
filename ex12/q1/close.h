#ifndef CLOSE_H
#define CLOSE_H

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

struct Point {
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

struct Compare {
    bool operator()(const Point& p1, const Point& p2) {
        double distance_p1 = std::sqrt(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z);
        double distance_p2 = std::sqrt(p2.x * p2.x + p2.y * p2.y + p2.z * p2.z);
        return distance_p1 < distance_p2; //Compare distances to the origin
    }
};

std::vector<Point> find_k_closest(int k, const std::vector<Point>& points);

#endif