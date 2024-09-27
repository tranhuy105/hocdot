#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// TLE lmao
int maxSubArray(vector<int>& nums) {
    int N = nums.size();
    int max = INT_MIN;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = nums[i];
        max = std::max(sum, max);
        for (int j = i+1; j < N; j++) {
            sum += nums[j];
            max = std::max(sum, max);
        }
    }

    return max;
}

// greedy
int maxSubArray2(vector<int>& nums) {
    int max = INT_MIN;
    int sum = 0;
    for (int it : nums) {
        sum += it;
        max = std::max(sum, max);
        if (sum < 0) {
            sum = 0;
        }
    }

    return max;
}


// divide and conquer
int f(vector<int>& nums, int low, int mid, int high) {
    int maxLeft = INT_MIN, maxRight = INT_MIN;

    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += nums[i];
        if (sum > maxLeft) {
            maxLeft = sum;
        }
    }

    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += nums[i];
        if (sum > maxRight) {
            maxRight = sum;
        }
    }

    return maxLeft + maxRight;
}

int maxSubArrayRec(vector<int>& nums, int low, int high) {
    if (low == high) {
        return nums[low];
    }

    int mid = (low + high) / 2;

    int maxLeft = maxSubArrayRec(nums, low, mid);
    int maxRight = maxSubArrayRec(nums, mid+1, high);
    int maxCross = f(nums, low, mid, high);

    return std::max(std::max(maxLeft, maxRight), maxCross);
}

int maxSubArray3(vector<int> &nums) {
    return maxSubArrayRec(nums, 0, nums.size() - 1);
}



int main() {
    vector<int> nums = {2,0,-3,2,1,0,1,-2};
    cout << maxSubArray3(nums) << endl; 
    return 0;
}