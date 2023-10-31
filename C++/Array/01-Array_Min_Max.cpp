#include <iostream>
#include <vector>

struct MinMaxPair {
    int min;
    int max;
};

MinMaxPair findMinMax(const std::vector<int>& arr) {
    int n = arr.size();
    MinMaxPair result;
    
    // Initialize min and max with the first element in the array
    result.min = arr[0];
    result.max = arr[0];

    // Loop through the array to find the minimum and maximum
    for (int i = 1; i < n; i++) {
        if (arr[i] < result.min) {
            result.min = arr[i];
        }
        if (arr[i] > result.max) {
            result.max = arr[i];
        }
    }

    return result;
}

int main() {
    std::vector<int> arr = {12, 34, 45, 6, 9, 56, 43, 78};
    
    MinMaxPair result = findMinMax(arr);

    std::cout << "Minimum value: " << result.min << std::endl;
    std::cout << "Maximum value: " << result.max << std::endl;

    return 0;
}
