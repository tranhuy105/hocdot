#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e9 + 7;

int f(int i, int k, vector<int>& a, vector<vector<int>>& mem) {
	if (k == 0) return 1;
	if (i < 0) return 0;
	if (mem[i][k] != -1) return mem[i][k];

	int res = f(i-1, k, a, mem);
	if (a[i] <= k) res = res + f(i-1, k - a[i], a, mem);

	return mem[i][k] = res;
}

long long findWays(vector<int>& arr, int k) {
    int n = arr.size();
    int zeroCount = count(arr.begin(), arr.end(), 0);
    vector<vector<int>> mem(arr.size(), vector<int>(k + 1, -1));
    int res = f(arr.size() - 1, k, arr, mem);

    return res * (pow(2, zeroCount));
}
int main() {
    int n; int k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findWays(arr, k) % MAX << endl;
    return 0;
}