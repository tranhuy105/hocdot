#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[int(nums.size() / 2)];
}

int majorityElement2(vector<int>& nums) {
    map<int, int> mpp;
    for (int  i = 0; i < nums.size(); ++i) {
        mpp[nums[i]]++;
        if (mpp[nums[i]] > nums.size()/2) {
            return nums[i];
        }
    }

    return 0;
}   

int majorityElement3(vector<int>& nums) {
    int el = -1;
    int cnt = 0;
    for (int it : nums ) {
        if (cnt == 0) {
            el = it;
        }

        if (it == el) {
            cnt++;
        } else {
            cnt--;
        }
    }

    return el;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement3(nums) << endl; 
    return 0;
}