#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperationsToSort(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;

    sort(nums.begin(), nums.end()); // Sort the array

    int minOperations = 0;
    int currentMin = nums[0];
    int currentCount = 1;

    // Iterate through each element in the sorted array
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] == currentMin)
        {

            currentCount++;
        }
        else
        {

            minOperations += currentCount;
            currentMin = nums[i];
            currentCount = 1;
        }
    }

    minOperations += currentCount;

    return minOperations;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3, 4, 5, 1}; // Sample array

    cout << "Minimum operations required to sort the array: " << minOperationsToSort(nums) << endl;

    return 0;
}
