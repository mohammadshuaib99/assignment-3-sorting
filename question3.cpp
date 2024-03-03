#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int findSortedK(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return -1;

    // Find the minimum and maximum values in the array
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    // Iterate through all possible values of K
    for (int k = minVal; k <= maxVal; ++k) {
        vector<int> modifiedArr(n);

        // Replace each index by |ai - K|
        for (int i = 0; i < n; ++i) {
            modifiedArr[i] = abs(arr[i] - k);
        }

        // Check if the modified array is sorted
        if (isSorted(modifiedArr)) {
            return k;
        }
    }

    return -1; // If no such integer K exists
}

int main() {
    vector<int> arr = {2, 4, 6, 7, 8}; // Sample array

    int K = findSortedK(arr);
    if (K != -1) {
        cout << "Integer K such that replacing each index of the array by |ai - K| results in a sorted array: " << K << endl;
    } else {
        cout << "No such integer K exists." << endl;
    }

    return 0;
}
