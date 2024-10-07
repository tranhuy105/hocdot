#include <iostream>
#include <vector>

using namespace std;

int findKRotation(vector<int> &arr) {
    int k = 0;
    for (int i = 1; i < arr.size(); i++) {
        k++;
        if (arr[i-1] > arr[i]) {
            return k;
        }
    }

    return 0;
}

int findKRotation2(vector<int>& arr) {
    int low = 0; int high = arr.size() - 1;
    int MIN = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) {
            MIN = arr[low] < arr[MIN] ? low : MIN;
            low = mid + 1;
        } else {
            MIN = arr[mid] < arr[MIN] ? mid : MIN;
            high = mid - 1;
        }
    }

    return MIN;
}

int main() {
    vector<int> arr = {5, 1, 2, 3, 4};
    cout << findKRotation2(arr) << endl;
    return 0;
}