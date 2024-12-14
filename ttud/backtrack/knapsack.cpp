/*
Đề bài:
Bài toán "Knapsack nhánh cận":
Cho `n` đồ vật, mỗi đồ vật có trọng lượng `w[i]` và giá trị `V[i]`. Có một túi với sức chứa tối đa là `W`. Nhiệm vụ là chọn một số lượng đồ vật sao cho:
- Tổng trọng lượng không vượt quá `W`.
- Tổng giá trị là lớn nhất.

Đầu vào:
- Một số nguyên `n` (số lượng đồ vật, `1 ≤ n ≤ 20`).
- Một số nguyên `W` (sức chứa của túi).
- Hai mảng `w` và `V`:
  - `w[i]` (trọng lượng của đồ vật thứ `i`).
  - `V[i]` (giá trị của đồ vật thứ `i`).

Đầu ra:
- Một số nguyên biểu thị tổng giá trị lớn nhất có thể đạt được.

Ví dụ:
Input:
4 5
2 3 4 1
3 4 5 6

Output:
Answer: 10

Giải thích:
- Với `n = 4` đồ vật và sức chứa `W = 5`:
  - Chọn đồ vật thứ 2 (trọng lượng 3, giá trị 4) và thứ 4 (trọng lượng 1, giá trị 6).
  - Tổng giá trị = 4 + 6 = 10.

Giải pháp:
1. **Nhánh cận (Branch and Bound):**
   - Thử tất cả các cách chọn đồ vật.
   - Loại bỏ những nhánh không tiềm năng dựa trên cận trên (upper bound).
   - Khi đạt được một tổ hợp hợp lệ, cập nhật giá trị lớn nhất (`maxValue`).

2. **Các thành phần chính:**
   - `check(v)`: Kiểm tra xem đồ vật `v` có thể được chọn hay không (dựa trên trọng lượng hiện tại).
   - `solution()`: Cập nhật giá trị lớn nhất nếu tổ hợp hiện tại tốt hơn.
   - `upperBound(k)`: Tính cận trên cho nhánh hiện tại, ước lượng giá trị tối đa có thể đạt được.
   - `Try(k)`: Thử tất cả các cách chọn đồ vật từ đồ vật `k` trở đi.

3. **Độ phức tạp:**
   - Với `n = 20`, thuật toán có thể duyệt qua tất cả các tổ hợp nhưng sử dụng nhánh cận để giảm số lượng nhánh cần xét, giúp tối ưu hóa.
*/


#include <iostream>
using namespace std;

int n, W;
int w[20], V[20];
int maxValue = 0;
int weight = 0;
int value = 0;

bool check(int v) {
    return (weight + w[v] <= W);
}

void solution() {
    maxValue = max(maxValue, value);
}

int upperBound(int k) {
    int remainingWeight = W - weight;
    int bound = value;

    for (int i = k; i < n; i++) {
        if (w[i] < remainingWeight) {
            bound += V[i];
            remainingWeight-=w[i];
        } else {
            bound += V[i] * (w[i] / remainingWeight);
            break;
        }
    }

    return bound;
}

void Try(int k) {
    for (int v = k; v < n; v++) {
        if (check(v)) {
            weight += w[v];
            value += V[v];

            solution();
            if (upperBound(v+1) > maxValue) {
                Try(v + 1);
            }

            weight -= w[v];
            value -= V[v];
        }
    }
}


int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }

    Try(0);

    cout << "Answer: " << maxValue << endl;

    return 0;
}
