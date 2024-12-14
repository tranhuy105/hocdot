#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Cho một mảng số nguyên `arr` và một số nguyên `k`. Nhiệm vụ là kiểm tra xem có hai phần tử bất kỳ trong mảng có giá trị bằng nhau và khoảng cách giữa chỉ số của chúng không vượt quá `k`.

Đầu vào:
- Một mảng số nguyên `arr`.
- Một số nguyên `k` - khoảng cách tối đa giữa các phần tử.

Đầu ra:
- Trả về `true` nếu tồn tại hai phần tử thỏa mãn điều kiện, ngược lại trả về `false`.

Ví dụ:
Input:
arr = {1, 2, 1}
k = 0

Output:
false

Giải thích:
- Không có hai phần tử nào thỏa mãn điều kiện cách nhau ≤ k và có giá trị bằng nhau.
*/


bool containsNearbyDuplicate(vector<int>& arr, int k) {
    unordered_set<int> window;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (window.find(arr[i]) != window.end()) return true;

        window.insert(arr[i]);
        if (window.size() > k) {
            window.erase(arr[i-k]);
        }
    }

    return false;
}


int main() {
    vector<int> arr = {1,2,1};
    int k = 0;
    cout << containsNearbyDuplicate(arr, k) << endl;
}

