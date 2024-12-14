#include <iostream>
#include <vector>

using namespace std;

/*
Đề bài:
Viết một chương trình để sắp xếp một mảng gồm các số 0, 1, và 2 theo thứ tự tăng dần mà không sử dụng thuật toán sắp xếp thông thường (như quicksort, mergesort, v.v.).

Yêu cầu:
- Thực hiện việc sắp xếp tại chỗ (in-place).
- Tối ưu hóa về thời gian và không gian.
- Sử dụng các phương pháp như đếm tần suất hoặc ba con trỏ.

Đầu vào:
- Một vector số nguyên `nums` chỉ chứa các số 0, 1 và 2.

Đầu ra:
- Mảng `nums` được sắp xếp theo thứ tự tăng dần.

Ví dụ:
- Input: nums = {2, 0, 2, 1, 1, 0}
- Output: {0, 0, 1, 1, 2, 2}

Gợi ý:
- Phương pháp 1: Duyệt qua mảng để đếm số lần xuất hiện của các số 0, 1, và 2, sau đó ghi đè lại mảng.
- Phương pháp 2: Sử dụng thuật toán ba con trỏ (Dutch National Flag Algorithm) để sắp xếp mảng trong một lần duyệt.
*/


void sortColors(vector<int>& nums) {
    int zeroCount = 0, oneCount = 0;
    for (int it : nums) {
        if (it == 0) zeroCount++;
        else if (it == 1) oneCount++;
    }

    for (int i = 0; i < zeroCount; i++) {
        nums[i] = 0;
    }

    for (int i = zeroCount; i < zeroCount + oneCount; i++) {
        nums[i] = 1;
    }

    for (int i = zeroCount + oneCount; i < nums.size(); i++) {
        nums[i] = 2;
    }
}

void sortColors3Pointer(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        switch (nums[mid])
        {
        case 0:
            swap(nums[mid], nums[low]);
            low++; mid++;
            break;
        case 1:
            mid++;    
            break;
        default:
            swap(nums[mid], nums[high]);
            high--;
            break;
        }
    }
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sortColors3Pointer(nums);
    for (int it : nums) {
        cout << it << " ";
    } 
    cout << endl;
    return 0;
}