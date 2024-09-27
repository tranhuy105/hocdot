#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int low = 0; int high = n - 1;
    pair<int, int> ans = {-1,-1};
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == x) {
            ans.first = x;
            ans.second = x;
            return ans;
        }

        if (a[mid] < x) {
            low = mid + 1;
            ans.first = a[mid];
        } else {
            high = mid - 1;
            ans.second = a[mid];
        }

    }

    return ans;
}

int main() {
    vector<int> a = {3};
    pair<int, int> ans = getFloorAndCeil(a, a.size(), 3);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}