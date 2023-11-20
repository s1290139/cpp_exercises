#include "median.h"
using namespace std;

int main() {
    std::vector<double> data1 = {3.5, 2.0, 10.0, 5.0, 4.0}; //odd test
    std::vector<double> data2 = {3.0, 1.0, 4.0, 7.5}; //even test

    cout << "data1 : ";
    for (const auto &element : data1){
        cout << element << " ";
    }
    cout << endl;

    cout << "data2 : ";
    for (const auto &element : data2){
        cout << element << " ";
    }
    cout << endl;

    cout << "Median of data1(odd): " << compute_median(data1) << endl;
    cout << "Median of data2(even): " << compute_median(data2) << endl;

    return 0;
}
