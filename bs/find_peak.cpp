#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (n==1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[n-1] > nums[n-2]) return n - 1;

    int low = 1; int high = n - 2;
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] < nums[mid-1]) {
        high = mid - 1;
      } else if (nums[mid] < nums[mid+1]) {
        low = mid + 1;
      } else {
        return mid;
      }

    }

    return -1;
}

int main() {
    vector<int> arr = {3,4,3,2,1};
    cout << findPeakElement(arr) << endl;
    return 0;
}