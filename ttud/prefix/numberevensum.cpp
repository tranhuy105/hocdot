#include <iostream>
#include <vector>

using namespace std;

/*
Đề bài:
- Cho một mảng số nguyên `arr`.
- Tìm số lượng dãy con liên tiếp (subarray) mà tổng các phần tử của dãy là số chẵn.
- Trả về kết quả theo modulo 10^9 + 7.

Ý tưởng:
1. Dùng kỹ thuật prefix sum (tổng trước) để kiểm tra tính chẵn/lẻ của dãy con.
2. Duy trì hai biến:
   - odd_count: Số lượng tổng prefix lẻ đã gặp.
   - even_count: Số lượng tổng prefix chẵn đã gặp.
3. Khi gặp một phần tử mới:
   - Nếu tổng prefix hiện tại là chẵn:
     + Dãy con chẵn = số tổng prefix chẵn trước đó + chính nó (dãy con 1 phần tử).
   - Nếu tổng prefix hiện tại là lẻ:
     + Dãy con chẵn = số tổng prefix lẻ trước đó.
4. Sử dụng modulo 10^9 + 7 để tránh tràn số.
*/

int numOfSubarraysWithEvenSum(vector<int>& arr) {
    const int MOD = 1e9 + 7;

    int odd_count = 0;  // Số lượng tổng prefix lẻ
    int even_count = 1; // Số lượng tổng prefix chẵn (khởi tạo với 1 cho prefix rỗng)
    int result = 0;     // Kết quả lưu số dãy con có tổng chẵn
    int prefix_sum = 0; // Tổng prefix hiện tại

    // Duyệt qua các phần tử trong mảng
    for (int num : arr) {
        prefix_sum += num; // Cập nhật tổng prefix

        if (prefix_sum % 2 == 0) {
            // Nếu tổng prefix hiện tại là chẵn
            result = (result + even_count) % MOD; // Dãy con chẵn = số tổng prefix chẵn trước đó
            even_count++; // Cập nhật số lượng tổng prefix chẵn
        } else {
            // Nếu tổng prefix hiện tại là lẻ
            result = (result + odd_count) % MOD; // Dãy con chẵn = số tổng prefix lẻ trước đó
            odd_count++; // Cập nhật số lượng tổng prefix lẻ
        }
    }

    return result; // Trả về kết quả
}

int main() {
    vector<int> arr = {1, 3, 5}; // Mảng đầu vào
    cout << "Số lượng dãy con có tổng chẵn: " << numOfSubarraysWithEvenSum(arr) << endl; // Output
    return 0;
}
