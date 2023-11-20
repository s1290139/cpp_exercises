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
    
    // 中央値からの距離に基づいてソートするための比較関数を定義
    auto compare = [median](double a, double b) {
        return abs(a - median) < abs(b - median);
    };
    
    // 中央値からの距離でソートする
    sort(arr.begin(), arr.end(), compare);

    // k個の最も近い要素を取得
    vector<double> closest_elements(arr.begin(), arr.begin() + k);
    return closest_elements;
}