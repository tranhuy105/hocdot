#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Đề bài:
Tìm tất cả các bộ ba phần tử trong một mảng sao cho tổng của chúng bằng k.
Yêu cầu:
- Các bộ ba phần tử phải là duy nhất (không trùng lặp về giá trị, bất kể thứ tự).
- Kết quả trả về là danh sách các bộ ba phần tử.

Đầu vào:
- Một mảng số nguyên `nums`.
- Một số nguyên `k` (giá trị tổng cần đạt).

Đầu ra:
- Một vector chứa các bộ ba số nguyên sao cho tổng của chúng bằng k.
*/

vector<vector<int>> threeSumK(vector<int>& nums, int k) {
    // Bước 1: Sắp xếp mảng để dễ dàng loại bỏ trùng lặp
    sort(nums.begin(), nums.end());
    vector<vector<int>> solutionSet;

    // Bước 2: Duyệt qua từng phần tử làm phần tử cố định
    for (int i = 0; i < nums.size(); i++) {
        // Bỏ qua phần tử trùng lặp
        if (i > 0 && nums[i] == nums[i-1]) continue;

        // Bước 3: Dùng hai con trỏ left và right để tìm bộ ba
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if (sum == k) {
                // Nếu tổng bằng k, thêm vào danh sách kết quả
                solutionSet.push_back({nums[i], nums[left], nums[right]});

                // Dịch cả hai con trỏ để tiếp tục tìm các bộ ba khác
                left++;
                right--;

                // Bỏ qua các phần tử trùng lặp
                while (left < right && nums[left] == nums[left-1]) left++;
                while (left < right && nums[right] == nums[right+1]) right--;
            } else if (sum < k) {
                // Nếu tổng nhỏ hơn k, tăng con trỏ trái để tăng tổng
                left++;
            } else {
                // Nếu tổng lớn hơn k, giảm con trỏ phải để giảm tổng
                right--;
            }
        }
    }
    
    return solutionSet;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4}; // Mảng đầu vào
    int k = 0;                              // Tổng cần tìm (có thể thay đổi)

    vector<vector<int>> res = threeSumK(arr, k);
    for (vector<int> a : res) {
        for (int n : a) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
