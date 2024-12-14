#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// my bad solution lmao
vector<int> productExceptSelfa(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n), suffix(n);
    prefix[0] = nums[0]; suffix[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * nums[i]; 
    }

    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i+1] * nums[i];
    }

    vector<int> ans(n);
    // n > 2
    ans[0] = suffix[1];
    ans[n - 1] = prefix[n-2];
    for (int i = 1; i < n-1;i++) {
        ans[i] = suffix[i+1] * prefix[i-1];
    }

    return ans;
}

// O(1) space
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size());
    int prefix = 1; ans[0] = prefix;
    for (int i = 1; i < nums.size();i++) {
        prefix*=nums[i-1];
        ans[i] = prefix;
    }

    int suffix = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        ans[i] = ans[i] * suffix;
        suffix*=nums[i];
    }

    return ans;
}


int main() {
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> re = productExceptSelf(nums);
    for (int it : re) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}