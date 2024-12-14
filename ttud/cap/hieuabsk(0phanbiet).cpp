#include <bits/stdc++.h>
using namespace std;

int countPairsWithDifferenceK(vector<int>& nums, int k) {
    unordered_map<int, int> freq; // Lưu tần suất các phần tử
    int count = 0;

    for (int num : nums) {
        // Kiểm tra nếu có số thỏa mãn |num - x| = k
        count += freq[num - k] + freq[num + k];
        freq[num]++; // Tăng tần suất của num
    }

    return count;
}

int main() {
    vector<int> nums = {1, 5, 3, 4, 2};
    int k = 2;
    cout << "Số cặp có hiệu tuyệt đối bằng " << k << ": " << countPairsWithDifferenceK(nums, k) << endl;
    return 0;
}
