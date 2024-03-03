#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<int> &nums, int k)
{
    // Sort the array in non-decreasing order
    sort(nums.begin(), nums.end());

    // Return the kth smallest element
    return nums[k - 1];
}

int main()
{
    // Test cases
    vector<int> arr1 = {3, 1, 4, 2, 5}; // Expected output: 2
    vector<int> arr2 = {8, 5, 7, 9, 6}; // Expected output: 7

    int k = 2; // Value of k

    cout << "Kth smallest element for arr1: " << kthSmallest(arr1, k) << endl;
    cout << "Kth smallest element for arr2: " << kthSmallest(arr2, k) << endl;

    return 0;
}
