#include"median.h"

double compute_median(std::vector<double> &arr) {
    //Calculate the element located in the center.
    size_t n = arr.size();
    size_t middle = n / 2;
    
    //use nth_element.
    std::nth_element(arr.begin(), arr.begin() + middle, arr.end());
    
    //odd number or even number?
    if (n % 2 == 0) {
        double median1 = arr[middle];
        std::nth_element(arr.begin(), arr.begin() + middle - 1, arr.end());
        double median2 = arr[middle - 1];
        return (median1 + median2) / 2.0;
    } else {
        return arr[middle];
    }
}