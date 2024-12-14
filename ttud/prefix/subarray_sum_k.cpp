#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count = 0; int pref = 0;
    unordered_map<int, int> prefMap;
    prefMap[0] = 1; // để tí cần tìm target là 0 vẫn có.
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        pref += nums[i];
        int target = pref - k;
        if (prefMap.find(target)!=prefMap.end()) {
            count += prefMap[target];
        }
        prefMap[pref]++;
    }

    return count;
}
// 0 1

int main() {
    vector<int> arr = {1};
    int k = 0;
    cout << subarraySum(arr, k) << endl;
    return 0;
}