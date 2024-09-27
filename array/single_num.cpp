#include <iostream>
#include <map>
#include <vector>
using namespace std;

    int singleNumber(vector<int>& nums) {
        int _xor = 0;
        for (int i = 0; i < nums.size(); i++) {
            _xor = _xor ^ nums[i];
        }

        return _xor;
    }

int main() {
    vector<int> arr = {4,1,2,1,2};
    cout << singleNumber(arr) << endl;
    return 0;
}