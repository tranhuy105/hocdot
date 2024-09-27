#include <iostream>
#include <map>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int sum = (nums.size() * (nums.size() + 1)) / 2;
    int s = 0; 
    for (int it : nums) {
        s += it;
    }
    return sum - s;
}

int missingNumber(vector<int>& nums) {
    int xor1=0,xor2=0;
    for (int i = 0; i < nums.size(); ++i) {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i+1);
    }
    
    return xor1 ^ xor2;
}