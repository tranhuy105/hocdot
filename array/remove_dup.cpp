#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDupSet(vector<int> &arr, int n) {
  set<int> st;
  for (int it : arr) {
    st.insert(it);
  }
  
  int index = 0;
  for (auto it : st) {
    arr[index++] = it;
  }

  return index;
}

int removeDupSorted(vector<int> &arr, int n) {
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      arr[i+1] = arr[j];
      i++;
    }
  }

  return i+1;
}
 
int main() {
  vector<int> arr = {1, 2, 2, 3, 5, 5, 5, 5};

  vector<int> arr1 = arr;
  int newSize1 = removeDupSet(arr1, arr1.size());
  cout << "Array after removing duplicates using set:\n";
  for (int i = 0; i < newSize1; i++) {
    cout << arr1[i] << " ";
  }
  cout << "\nNew size: " << newSize1 << endl;

  vector<int> arr2 = arr;
  int newSize2 = removeDupSorted(arr2, arr2.size());
  cout << "\nArray after removing duplicates (sorted assumption):\n";
  for (int i = 0; i < newSize2; i++) {
    cout << arr2[i] << " ";
  }
  cout << "\nNew size: " << newSize2 << endl;

  return 0;
}