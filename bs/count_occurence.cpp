#include <iostream>
#include <algorithm>

using namespace std;

int count(int arr[], int n, int x) {
	int lb = n;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            lb = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (lb == n || arr[lb] != x) {
        return 0;
    }
    left = 0, right = n - 1;
    int ub = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ub = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ub - lb;
}

int main() {
    int arr[] ={1};
    cout << count(arr, 1, 1) << endl;
    return 0;
}