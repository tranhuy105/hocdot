#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int zeroCount = 0, oneCount = 0;
    for (int it : nums) {
        if (it == 0) zeroCount++;
        else if (it == 1) oneCount++;
    }

    for (int i = 0; i < zeroCount; i++) {
        nums[i] = 0;
    }

    for (int i = zeroCount; i < zeroCount + oneCount; i++) {
        nums[i] = 1;
    }

    for (int i = zeroCount + oneCount; i < nums.size(); i++) {
        nums[i] = 2;
    }
}

void sortColors3Pointer(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        switch (nums[mid])
        {
        case 0:
            swap(nums[mid], nums[low]);
            low++; mid++;
            break;
        case 1:
            mid++;    
            break;
        default:
            swap(nums[mid], nums[high]);
            high--;
            break;
        }
    }
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    sortColors3Pointer(nums);
    for (int it : nums) {
        cout << it << " ";
    } 
    cout << endl;
    return 0;
}