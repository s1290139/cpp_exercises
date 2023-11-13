#include "sort.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {5, 2, 8, 3, 1, 7, 4, 6};

    std::cout << "Original numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    PL04::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted numbers (descending): ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
