#include "close.h"

std::vector<Point> find_k_closest(int k, const std::vector<Point>& points) {
    std::priority_queue<Point, std::vector<Point>, Compare> pq;

    for (const auto& point : points) {
        pq.push(point);
        if (pq.size() > k) {
            pq.pop(); //Keep the k closest points in the priority queue
        }
    }

    std::vector<Point> closest_points;
    while (!pq.empty()) {
        closest_points.push_back(pq.top());
        pq.pop();
    }
    
    return closest_points;
}