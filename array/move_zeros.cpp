#include <iostream>
#include <vector>

using namespace std;

/*
Đề bài:
Viết một chương trình để di chuyển tất cả các số 0 trong một mảng số nguyên về cuối mảng mà không thay đổi thứ tự tương đối của các số không phải 0.

Yêu cầu:
- Thực hiện việc di chuyển tại chỗ (in-place), không sử dụng mảng phụ nếu có thể.
- Tối ưu hóa về thời gian và không gian.

Đầu vào:
- Một vector số nguyên `nums`.

Đầu ra:
- Mảng `nums` sau khi tất cả các số 0 được di chuyển về cuối.

Ví dụ:
- Input: nums = {0, 1, 0, 3, 12}
- Output: {1, 3, 12, 0, 0}
*/


void moveZeroes(vector<int>& nums) {
    vector<int> temp;
    int zeroCnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        } else zeroCnt++;
    }

    while (zeroCnt--)
    {
        temp.push_back(0);
    }
    
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = temp[i];
    }
}

void moveZeroes2(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n && nums[i] != 0) {
        i++;
    }
    int j = i + 1;
    
    while (i < n && j < n) {
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}


int main() {
    vector<int> nums = {0, 1, 0, 3, 12};  
    moveZeroes2(nums);

    cout << "After moving zeros: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;

}