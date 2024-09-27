#include <iostream>
#include <vector>
using namespace std;

int isSorted(vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] < arr[i-1]) {
      return false;
    }
  }

  return true;
}

int main() {
  // vector<int> arr = {10, 7, 8, 9, 1, 5};
  vector<int> arr = {1, 2, 2, 3, 5, 5};
  cout << isSorted(arr) << endl;
  return 0;
}