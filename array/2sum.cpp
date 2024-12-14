#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
Đề bài:
Viết một chương trình để tìm hai chỉ số trong một mảng số nguyên sao cho tổng của các phần tử tại hai chỉ số đó bằng một giá trị mục tiêu (target) cho trước. 

Đầu vào:
- Một mảng số nguyên `nums`.
- Một số nguyên `target`.

Đầu ra:
- Một vector chứa hai chỉ số trong mảng `nums` sao cho tổng của hai phần tử tương ứng bằng `target`.
- Nếu không tìm được, trả về một vector rỗng.

Ví dụ:
- Input: nums = {2, 7, 11, 15}, target = 9
- Output: [0, 1] (vì nums[0] + nums[1] = 9)
*/



// o(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans; 
            }   
        }
    }     

    return ans;   
}

// o(nlogn)
vector<int> twoSumMap(vector<int>& nums, int target) {
    vector<int> ans;
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++) {
        if (mpp.find(target - nums[i]) != mpp.end()) {
            ans.push_back(i);
            ans.push_back(mpp[target - nums[i]]);
            return ans;
        }
        mpp[nums[i]] = i;
    }

    return ans;
}

// o(nlogn)
vector<int> twoSum2Pointer(vector<int>& nums, int target) {
    vector<pair<int, int>> sorted_nums;

    for (int i = 0; i < nums.size(); i++) {
        sorted_nums.push_back({nums[i], i});
    }

    sort(sorted_nums.begin(), sorted_nums.end());

    int left = 0; int right = sorted_nums.size() - 1;
    while (left < right) {
        int sum = sorted_nums[left].first + sorted_nums[right].first;
        if (sum == target) {
            return {sorted_nums[left].second, sorted_nums[right].second};
        } else if (sum < target) {
            left++;
        } else right--;
    }

    return {};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum2Pointer(nums, target);
    
    if (!result.empty()) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}