#include <iostream>
#include <vector>
using namespace std;

/*
Đề bài:
Đếm số nghiệm nguyên không âm của hệ phương trình tuyến tính:
    a₁ * x₁ + a₂ * x₂ + ... + aₙ * xₙ = M
Trong đó:
- a₁, a₂, ..., aₙ là các số nguyên dương.
- x₁, x₂, ..., xₙ là các số nguyên không âm (xᵢ >= 0).
- M là một số nguyên dương.

Input:
- Dòng đầu tiên: hai số nguyên n (số lượng biến) và M (giá trị tổng cần đạt được).
- Dòng thứ hai: n số nguyên dương a₁, a₂, ..., aₙ (các hệ số).

Output:
- In ra số lượng nghiệm nguyên không âm của hệ phương trình.

Ví dụ:
Input:
    3 5
    1 2 3
Output:
    5

Giải thích:
Hệ có các nghiệm:
1. (x₁, x₂, x₃) = (0, 0, 5)
2. (x₁, x₂, x₃) = (0, 1, 3)
3. (x₁, x₂, x₃) = (0, 2, 1)
4. (x₁, x₂, x₃) = (1, 0, 4)
5. (x₁, x₂, x₃) = (2, 0, 3)
*/

int count_solutions(int n, int M, const vector<int> &a)
{
    int sum = 0;

    // Tính tổng các hệ số a[i]
    for (int i = 0; i < n; i++)
        sum += a[i];
    
    // Đặt lại Y = X - 1, thay đổi phạm vi thành số không âm (N* -> N)
    // Cập nhật giá trị M mới: M = M - sum(a[i])
    M -= sum;

    // Nếu M < 0, không thể có nghiệm vì không thể đạt giá trị tổng M
    if (M < 0)
    {
        return 0;
    }

    // Khởi tạo mảng dp để lưu số cách tính tổng
    vector<int> dp(M + 1, 0);
    dp[0] = 1; // Có duy nhất 1 cách để tạo tổng 0 (không chọn gì)

    // Duyệt qua từng hệ số a[j]
    for (int j = 0; j < n; j++)
    {
        // Cập nhật dp[i] cho mỗi giá trị tổng từ a[j] đến M
        for (int i = a[j]; i <= M; i++)
        {
            dp[i] += dp[i - a[j]]; // Thêm cách từ dp[i - a[j]]
        }
    }

    // Trả về số cách đạt tổng M
    return dp[M];
}

int main()
{
    // Nhập số lượng biến n và giá trị tổng M
    int n, M;
    cin >> n >> M;

    // Nhập hệ số a[i] của phương trình
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // In ra số lượng nghiệm nguyên không âm
    cout << count_solutions(n, M, a) << endl;

    return 0;
}
