#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum = 0;
        sum += nums[i];
        if (nums[i] == k) {
            count++;
        }
        for (int j = i + 1; j < nums.size(); j++) {
            sum+=nums[j];
            if (sum == k) {
                count++;
            }
        }
    }

    return count;
}

int subarraySum2(vector<int>& nums, int k) {
    int sumPrefix[nums.size()] = {0};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum+=nums[i];
        sumPrefix[i] = sum;
    }

    unordered_map<long, int> mpp;
    int count = 0;
    mpp[0] = 1;
    for (int i = 0; i < nums.size();i++) {
        if (k == 0) {
            count+=mpp[sumPrefix[i]-k];
            mpp[sumPrefix[i]]++;
        } else {
            mpp[sumPrefix[i]]++;
            count+=mpp[sumPrefix[i]-k];
        }
    }

    return count;
}

int subarraySum3(vector<int>& nums, int k) {
    
}

int main() {
    vector<int> arr = {1,-1,0};
    cout << subarraySum2(arr, 0) << endl;
    return 0;
}