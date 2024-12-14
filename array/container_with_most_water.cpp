#include <iostream>
#include <vector>

using namespace std;

/*
Đề bài:
Viết một chương trình để tìm diện tích lớn nhất của một vùng chứa nước được hình thành bởi hai đường thẳng đứng trong một mảng, với chiều cao của mỗi đường thẳng được biểu thị bởi các phần tử trong mảng.

Yêu cầu:
- Hai đường thẳng được chọn để tạo thành một vùng chứa nước với đáy là khoảng cách giữa chúng, và chiều cao là chiều cao nhỏ hơn của hai đường thẳng.
- Tìm diện tích lớn nhất có thể chứa nước.

Đầu vào:
- Một mảng số nguyên `height` đại diện cho chiều cao của các đường thẳng.

Đầu ra:
- Một số nguyên biểu thị diện tích lớn nhất của vùng chứa nước.

Ví dụ:
- Input: height = {1, 8, 6, 2, 5, 4, 8, 3, 7}
- Output: 49 (vùng chứa nước lớn nhất được tạo bởi các đường thẳng tại chỉ số 1 và 8)
*/


int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int m = -1;

    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        m = max(m, area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return m;
}

int main() {
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(arr) << endl;
    return 0;
}