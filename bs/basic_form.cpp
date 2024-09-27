#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs(vector<int>& nums, int low, int high, int target) {
    if (high < low) return -1;

    int mid = low + (high - low) /2;
    if (nums[mid] == target) return mid;
    if (nums[mid] > target) return bs(nums, low, mid - 1, target);
    return bs(nums, mid + 1, high, target);
}

int bs_iterate(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int mid = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    return mid;
}

int search(vector<int>& nums, int target) {
    return bs(nums, 0, nums.size() - 1, target);
}

int main() {
    vector<int> arr = {-1};
    cout << bs_iterate(arr, 2) << endl;
    return 0;
}