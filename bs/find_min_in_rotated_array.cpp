#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int MIN = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid]) {
            MIN = min(MIN, nums[low]);
            low = mid + 1;
        } else {
            MIN = min(MIN, nums[mid]);
            high = mid - 1;
        }
    }

    return MIN;
}

int main() {
    vector<int> arr = {1};
    cout << findMin(arr) << endl;
    return 0;
}