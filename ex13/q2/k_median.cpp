#include "k_median.h"

double compute_median(std::vector<double> &arr) {
    //Calculate the element located in the center.
    size_t n = arr.size();
    size_t middle = n / 2;
    
    //use nth_element.
    nth_element(arr.begin(), arr.begin() + middle, arr.end());
    
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

vector<double> compute_k_closest(vector<double> &arr, int k) {
    double median = compute_median(arr);
    
    //sort
    auto compare = [median](double a, double b) {
        return abs(a - median) < abs(b - median);
    };
    
    //Create an array excluding the median.
    vector<double> arr_without_median;
    for (const auto &num : arr) {
        if (num != median) {
            arr_without_median.push_back(num);
        }
    }
    
    //Sort by distance from non-median.
    sort(arr_without_median.begin(), arr_without_median.end(), compare);

    //Get the k nearest elements.
    vector<double> closest_elements;
    for (int i = 0; i < k && i < arr_without_median.size(); ++i) {
        closest_elements.push_back(arr_without_median[i]);
    }
    return closest_elements;
}