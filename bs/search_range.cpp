#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    vector<int> ans = {-1,-1};
    if (lb == nums.size() || nums[lb] != target) {
        return ans;
    }

    ans[0] = lb;
    int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    ans[1] = ub - 1;

    return ans;
}

int main() {
    vector<int> a = {5,7,7,8,8,10};
    vector<int> ans = searchRange(a, 6);
    for (int it : ans) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}