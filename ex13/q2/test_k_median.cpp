#include "k_median.h"
using namespace std;

int main() {
    vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    int k = 3;

    cout << "Data: ";
    for (const auto &element : data) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Median of data: " << compute_median(data) << endl;

    vector<double> closest = compute_k_closest(data, k);

    cout << "Closest " << k << " elements to the median: ";
    for (const auto &element : closest) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}