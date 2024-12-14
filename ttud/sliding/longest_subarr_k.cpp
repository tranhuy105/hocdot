#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Hàm phụ để kiểm tra độ dài dãy con dài nhất thỏa điều kiện:
Mỗi số trong dãy con xuất hiện ít nhất `k` lần.
*/
int helper(vector<int>& arr, int k, int start, int end) {
    if (end - start < k) return 0; // Nếu dãy nhỏ hơn `k`, không thể hợp lệ

    // Đếm tần suất xuất hiện của các số trong khoảng [start, end)
    unordered_map<int, int> freq;
    for (int i = start; i < end; ++i) {
        freq[arr[i]]++;
    }

    // Tìm phần tử không hợp lệ (xuất hiện ít hơn `k` lần)
    for (int i = start; i < end; ++i) {
        if (freq[arr[i]] < k) {
            // Chia dãy tại phần tử không hợp lệ `arr[i]`
            int left = helper(arr, k, start, i);   // Dãy con bên trái
            int right = helper(arr, k, i + 1, end); // Dãy con bên phải
            return max(left, right); // Lấy kết quả tối đa giữa hai bên
        }
    }

    // Nếu tất cả các số đều hợp lệ, trả về độ dài của dãy
    return end - start;
}

/*
Hàm chính để tìm độ dài dãy con dài nhất mà mỗi số xuất hiện ít nhất `k` lần.
*/
int longestSubarrayDivideAndConquer(vector<int>& arr, int k) {
    return helper(arr, k, 0, arr.size());
}

int main() {
    // Đầu vào mẫu
    vector<int> arr = {1, 2, 2, 3, 1, 3, 3};
    int k = 2;

    // Gọi hàm chính
    cout << "Độ dài dãy con dài nhất: " << longestSubarrayDivideAndConquer(arr, k) << endl;

    return 0;
}
