#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0; int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> arr = {1,3};
    cout << searchInsert(arr, 2) << endl;
    return 0;
}