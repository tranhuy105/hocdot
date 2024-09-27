#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myReverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k <= 0) return;

    k = k % n;
    if (k == 0) return;
    k = n - k; // for right rotate
    
    vector<int> temp(nums.begin(), nums.begin() + k); 
    for (int i = k; i < n; i++) {
        nums[i-k] = nums[i];
    }

    for (int i = 0; i < k; i++) {
        nums[n - k + i] = temp[i];
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k <= 0) return;

    k = k % n; // Normalize k
    if (k == 0) return;

    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}



int main() {
    vector<int> nums = {1, 2};
    int k = 3; // Number of elements to rotate

    rotate(nums, k);

    // Output the rotated vector
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}