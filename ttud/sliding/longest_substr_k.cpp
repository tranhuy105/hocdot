#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Đề bài:
Cho chuỗi `s` và số nguyên `k`, hãy tìm độ dài của chuỗi con dài nhất mà
mỗi ký tự trong chuỗi con đó xuất hiện ít nhất `k` lần.
*/

int longestSubstring(string s, int k) {
    int maxLength = 0; // Biến lưu độ dài tối đa của chuỗi con hợp lệ
    int n = s.size();  // Độ dài của chuỗi đầu vào

    // Thử với số lượng ký tự duy nhất trong chuỗi con từ 1 đến 26 (chữ cái thường)
    for (int numUnique = 1; numUnique <= 26; ++numUnique) {
        vector<int> freq(26, 0); // Mảng đếm tần suất xuất hiện của mỗi ký tự
        int start = 0, end = 0;  // Hai con trỏ để quản lý cửa sổ trượt
        int unique = 0;         // Số lượng ký tự duy nhất trong cửa sổ hiện tại
        int atLeastK = 0;       // Số ký tự trong cửa sổ có tần suất >= k

        while (end < n) {
            // Mở rộng cửa sổ bằng cách thêm ký tự s[end]
            if (freq[s[end] - 'a'] == 0) unique++; // Thêm ký tự mới
            freq[s[end] - 'a']++; // Tăng tần suất ký tự s[end]
            if (freq[s[end] - 'a'] == k) atLeastK++; // Nếu tần suất đạt k, tăng atLeastK
            end++;

            // Thu hẹp cửa sổ nếu số lượng ký tự duy nhất > numUnique
            while (unique > numUnique) {
                if (freq[s[start] - 'a'] == k) atLeastK--; // Giảm số ký tự đủ điều kiện
                freq[s[start] - 'a']--; // Giảm tần suất ký tự s[start]
                if (freq[s[start] - 'a'] == 0) unique--; // Giảm số ký tự duy nhất
                start++;
            }

            // Kiểm tra xem cửa sổ hiện tại có hợp lệ không
            // (đủ numUnique ký tự duy nhất và mỗi ký tự xuất hiện ít nhất k lần)
            if (unique == numUnique && unique == atLeastK) {
                maxLength = max(maxLength, end - start); // Cập nhật độ dài tối đa
            }
        }
    }

    return maxLength; // Trả về độ dài chuỗi con dài nhất hợp lệ
}

int main() {
    // Đầu vào mẫu
    string s = "ababbc";
    int k = 2;

    // Kết quả đầu ra
    cout << "Độ dài chuỗi con dài nhất: " << longestSubstring(s, k) << endl;
    return 0;
}
