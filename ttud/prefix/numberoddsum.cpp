#include <iostream>
#include <vector>

using namespace std;

/*
Đề bài:
- Cho một mảng số nguyên `arr`.
- Tìm số lượng dãy con liên tiếp (subarray) mà tổng các phần tử của dãy là số lẻ.
- Trả về kết quả theo modulo 10^9 + 7.

Ví dụ:
Input: arr = [1, 3, 5]
Output: 4
Giải thích: Các dãy con có tổng lẻ bao gồm: [1], [1, 3, 5], [3], [5].

Ràng buộc:
1. 1 <= arr.length <= 10^5
2. 1 <= arr[i] <= 100
*/

/*
Ý tưởng:
1. Dùng kỹ thuật prefix sum (tổng trước) để tính tổng của bất kỳ dãy con liên tiếp.
2. Một dãy con có tổng là số lẻ nếu và chỉ nếu:
   - Tổng prefix tại điểm cuối của dãy con (prefix_sum) và tại điểm bắt đầu có tính chất khác nhau:
     + Một tổng là lẻ và tổng còn lại là chẵn.
3. Duy trì hai biến đếm:
   - odd_count: Số lượng tổng prefix lẻ đã gặp.
   - even_count: Số lượng tổng prefix chẵn đã gặp.
4. Khi gặp một phần tử mới:
   - Nếu tổng prefix hiện tại (prefix_sum) là lẻ:
     + Có thể tạo ra số dãy con lẻ bằng cách kết hợp với các tổng prefix chẵn trước đó.
     + Cập nhật odd_count.
   - Nếu tổng prefix hiện tại (prefix_sum) là chẵn:
     + Có thể tạo ra số dãy con lẻ bằng cách kết hợp với các tổng prefix lẻ trước đó.
     + Cập nhật even_count.
5. Sử dụng modulo 10^9 + 7 để tránh tràn số.
*/

int numOfSubarrays(vector<int>& arr) {
    const int MOD = 1e9 + 7;

    int odd_count = 0;  // Số lượng tổng prefix lẻ
    int even_count = 1; // Số lượng tổng prefix chẵn (khởi tạo với 1 để bao gồm prefix rỗng)
    int result = 0;     // Kết quả lưu số dãy con có tổng lẻ
    int prefix_sum = 0; // Tổng prefix hiện tại

    // Duyệt qua các phần tử trong mảng
    for (int num : arr) {
        prefix_sum += num; // Cập nhật tổng prefix

        if (prefix_sum % 2 == 0) {
            // Nếu tổng prefix hiện tại là chẵn
            result = (result + odd_count) % MOD; // Các dãy con lẻ kết thúc tại đây
            even_count++; // Cập nhật số lượng tổng prefix chẵn
        } else {
            // Nếu tổng prefix hiện tại là lẻ
            result = (result + even_count) % MOD; // Các dãy con lẻ kết thúc tại đây
            odd_count++; // Cập nhật số lượng tổng prefix lẻ
        }
    }

    return result; // Trả về kết quả
}

int main() {
    vector<int> arr = {1, 3, 5}; // Mảng đầu vào
    cout << "Số lượng dãy con có tổng lẻ: " << numOfSubarrays(arr) << endl; // Output: 4
    return 0;
}
