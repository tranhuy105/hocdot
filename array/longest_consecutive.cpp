#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;



int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    sort(nums.begin(), nums.end());
    int count = 1;
    int maximum = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1]) {
            maximum = max(maximum, count);
            continue;
        }

        if (nums[i] - 1 == nums[i-1]) {
            count++;
            maximum = max(maximum, count);
        } else {
            count = 1;
            maximum = max(maximum, count);
        }
    }

    return maximum;
}

int main() {
    // 0 1 1 2
    vector<int> arr = {2};
    cout << longestConsecutive(arr) << endl;
    return 0;
}