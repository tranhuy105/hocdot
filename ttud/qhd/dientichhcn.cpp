#include <bits/stdc++.h>
using namespace std;

// Hàm phụ: Tìm diện tích lớn nhất trong histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    vector<int> left(n, -1), right(n, n);

    // Tính mảng left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Tính mảng right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = (st.empty() ? n : st.top());
        st.push(i);
    }

    // Tính diện tích lớn nhất
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }

    return maxArea;
}

// Hàm chính: Tìm diện tích hình chữ nhật lớn nhất trong ma trận nhị phân
int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        // Cập nhật histogram cho hàng i
        for (int j = 0; j < m; j++) {
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }

        // Tìm diện tích lớn nhất cho histogram hiện tại
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix) << endl;

    return 0;
}
