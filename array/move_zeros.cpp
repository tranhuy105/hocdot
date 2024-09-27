#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    vector<int> temp;
    int zeroCnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            temp.push_back(nums[i]);
        } else zeroCnt++;
    }

    while (zeroCnt--)
    {
        temp.push_back(0);
    }
    
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = temp[i];
    }
}

void moveZeroes2(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n && nums[i] != 0) {
        i++;
    }
    int j = i + 1;
    
    while (i < n && j < n) {
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}


int main() {
    vector<int> nums = {0, 1, 0, 3, 12};  
    moveZeroes2(nums);

    cout << "After moving zeros: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;

}