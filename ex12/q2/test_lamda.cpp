#include "lamda.h"


int main() {
    std::vector<Point> points = {Point(1.0, 1.0, 1.0), Point(2.0, 2.0, 2.0), Point(3.0, 3.0, 3.0), Point(4.0, 4.0, 4.0)};
    int k = 2;
    std::vector<Point> closest = find_k_closest_lambda(k, points);

    std::cout << "The " << k << " closest points to the origin are:" << std::endl;
    for (const auto& point : closest) {
        std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
    }

    return 0;
}
