#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

/*
Đề bài:
Viết một chương trình để tìm tất cả các "phần tử dẫn đầu" (leaders) trong một mảng. Một phần tử được coi là "phần tử dẫn đầu" nếu nó lớn hơn hoặc bằng tất cả các phần tử nằm bên phải nó trong mảng.

Yêu cầu:
- Duyệt mảng từ cuối lên để tìm các "phần tử dẫn đầu".
- Các "phần tử dẫn đầu" phải được trả về theo thứ tự xuất hiện ban đầu trong mảng.

Đầu vào:
- Một số nguyên `n` đại diện cho độ dài của mảng.
- Một mảng số nguyên `arr` có độ dài `n`.

Đầu ra:
- Một vector chứa các phần tử dẫn đầu trong mảng.

Ví dụ:
- Input: arr = {30, 10, 10, 5}, n = 4
- Output: {30, 10, 5} (vì các phần tử dẫn đầu là 30, 10, và 5)
*/


using namespace std;

vector<int> leaders(int n, int arr[]) {
    int m = INT_MIN;
    vector<int> a;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= m) {
            a.push_back(arr[i]);
        }
        m = max(m, arr[i]);
    }

    reverse(a.begin(), a.end());
    return a;
}

int main() {
    int arr[] = {30, 10, 10, 5};
    vector<int> a = leaders(4, arr);
    for (int it : a) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}