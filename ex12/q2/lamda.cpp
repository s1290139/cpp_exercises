#include "lamda.h"

std::vector<Point> find_k_closest_lambda(int k, const std::vector<Point>& points) {
    auto compare = [](const Point& p1, const Point& p2) {
        double distance_p1 = std::sqrt(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z);
        double distance_p2 = std::sqrt(p2.x * p2.x + p2.y * p2.y + p2.z * p2.z);
        return distance_p1 < distance_p2; //Compare distances to the origin in reverse
    };

    std::priority_queue<Point, std::vector<Point>, decltype(compare)> pq(compare);

    for (const auto& point : points) {
        pq.push(point);
        if (pq.size() > k) {
            pq.pop(); //Keep the k closest points in the priority queue
        }
    }

    std::vector<Point> closest_points;
    while (!pq.empty()) {
        closest_points.insert(closest_points.begin(), pq.top()); //Insert at the beginning of the vector
        pq.pop();
    }

    return closest_points;
}