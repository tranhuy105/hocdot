#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> leaders(int n, int arr[]) {
    int m = INT_MIN;
    vector<int> a;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= m) {
            a.push_back(arr[i]);
        }
        m = max(m, arr[i]);
    }

    reverse(a.begin(), a.end());
    return a;
}

int main() {
    int arr[] = {30, 10, 10, 5};
    vector<int> a = leaders(4, arr);
    for (int it : a) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}