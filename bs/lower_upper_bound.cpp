#include <iostream>
#include <vector>

using namespace std;

int myUpperBound(vector<long long> &v, long long n, long long x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] > x) {
            // This is a potential candidate, search left
            high = mid - 1;
        } else {
            // Skip all elements less than or equal to x, search right
            low = mid + 1;
        }
    }

    return low;
}

int myLowerBound(vector<long long> &v, long long n, long long x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] >= x) {
            // This is a potential candidate, search left
            high = mid - 1;
        } else {
            // Skip all elements less than x, search right
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    vector<long long> arr = {1,6,8,8,9};
    cout << myLowerBound(arr, arr.size(), 8) << endl;
    return 0;
}