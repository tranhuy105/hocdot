#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0;
    int m = 0;

    for (int it : nums) {
        if (it == 1) {
            cnt++;
            m = max(cnt, m);
        } else {
            cnt = 0;
        }
    }

    return m;
}

int main() {
    vector<int> arr = {1,1,1,1,0,0,0,1,1,0,0,1,0,1};
    cout << findMaxConsecutiveOnes(arr) << endl;
    return 0;
}