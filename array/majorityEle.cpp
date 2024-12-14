#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
Đề bài:
Viết một chương trình để tìm "phần tử chiếm đa số" (majority element) trong một mảng số nguyên. "Phần tử chiếm đa số" được định nghĩa là phần tử xuất hiện nhiều hơn n/2 lần, với n là độ dài của mảng.

Đầu vào:
- Một vector số nguyên `nums`.

Đầu ra:
- Một số nguyên biểu thị phần tử chiếm đa số trong mảng.

Yêu cầu:
- Đảm bảo rằng luôn có một phần tử chiếm đa số trong mảng.
- Chương trình cần được tối ưu hóa về thời gian và không gian.

Ví dụ:
- Input: nums = {2, 2, 1, 1, 1, 2, 2}
- Output: 2 (vì số 2 xuất hiện 4 lần, lớn hơn n/2 = 3)

Gợi ý:
- Có thể sử dụng các phương pháp khác nhau:
  1. Sắp xếp và chọn phần tử giữa mảng.
  2. Sử dụng cấu trúc dữ liệu `map` để đếm tần suất xuất hiện.
  3. Thuật toán Moore’s Voting để tìm phần tử chiếm đa số trong O(n) thời gian và O(1) không gian.
*/


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