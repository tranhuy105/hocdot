#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int breakPoint = -1;

    // Step 1: Find the largest index i such that nums[i] < nums[i + 1]
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            breakPoint = i;
            break;
        }
    }

    // Step 2: If no such index exists, the permutation is the last permutation, reverse it
    if (breakPoint == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    // Step 3: Find the largest index j such that nums[j] > nums[breakPoint]
    // Normally this have to be find the smallest in those larger, but it always in descending order when we try to find the breakpoint
    for (int i = nums.size() - 1; i > breakPoint; i--) {
        if (nums[i] > nums[breakPoint]) {
            swap(nums[breakPoint], nums[i]);
            break;
        }
    }

    // Step 4: Reverse the sequence from breakPoint + 1 to the end
    sort(nums.begin() + breakPoint + 1, nums.end());
}

int main() {
    vector<int> arr = {1,3,2};
    nextPermutation(arr);
    for (int it : arr) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}