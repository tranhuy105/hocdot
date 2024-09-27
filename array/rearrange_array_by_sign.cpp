#include <iostream>
#include <vector>

using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;
    for (int it : nums) {
        if (it > 0) {
            pos.push_back(it);
        } else {
            neg.push_back(it);
        }
    }

    for (int i = 0; i < nums.size(); i+=2) {
        nums[i] = pos[i/2];
        nums[i+1] = neg[i/2];
    }

    return nums;
}

vector<int> rearrangeArray2(vector<int>& nums) {
    vector<int> ans(nums.size());
    int neg = 1;
    int pos = 0;
    for (int it : nums) {
        if (it > 0) {
            ans[pos] = it;
            pos+=2;
        } else {
            ans[neg] = it;
            neg+=2;
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {-1,1};
    arr = rearrangeArray2(arr);
    for (int it : arr) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}