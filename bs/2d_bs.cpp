#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int val = matrix[mid / cols][mid % cols];

        if (val == target) return true;
        if (val < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> v;
    v.push_back({1,3,5,7});
    v.push_back({10,11,16,20});
    v.push_back({23,30,34,60});
    cout << searchMatrix(v, 13) << endl;
    return 0;
}