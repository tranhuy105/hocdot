#include <bits/stdc++.h>
using namespace std;

#define INF (long long) 1e18

int n;
vector <int> arr; 

int main() {
    cin >> n;
    arr.resize(n+1);
    vector <long long> S(n+1);
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
        S[i] = (S[i-1] + arr[i]);
    }
    
    long long f[2];
    f[1] = INF;
    int tmp; 
    long long res = -INF; 
    for (int i = 1; i <= n; i++) {
        tmp = abs(S[i]) % 2; // Kiểm tra tính chẵn/lẻ của tổng tích lũy S[i]

        if (f[tmp] != INF) 
            res = max(res, S[i] - f[tmp]); 
            // Nếu đã gặp tổng tích lũy có cùng tính chất chẵn/lẻ trước đó,
            // tính tổng dãy con và cập nhật kết quả lớn nhất

        f[tmp] = min(f[tmp], S[i]); 
            // Cập nhật giá trị nhỏ nhất của tổng tích lũy cho tính chất chẵn/lẻ hiện tại
    }

    if (res == -INF) cout << "NOT_FOUND" << endl;
    else cout << res << endl;
    
    return 0;
}