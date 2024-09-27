#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];  // Choose the first element as the pivot
  int i = low;
  int j = high;

  while (i < j) {
    // Find element greater than pivot
    while (arr[i] <= pivot && i < high) {
      i++;
    }
    // Find element less than or equal to pivot
    while (arr[j] > pivot && j > low) {
      j--;
    }
    // If i is still less than j, swap the elements
    if (i < j) swap(arr[i], arr[j]);
  }

  // Swap the pivot into its correct position
  swap(arr[low], arr[j]);
  return j;  // Return the partition index
}

void qs(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pIndex = partition(arr, low, high);  // Get the partition index
    qs(arr, low, pIndex - 1);  // Recursively sort the left part
    qs(arr, pIndex + 1, high); // Recursively sort the right part
  }
}

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;  // Temporary vector to hold merged result
  int left = low;
  int right = mid + 1;

  // Merge the two halves [low..mid] and [mid+1..high]
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  // Copy remaining elements from the left half
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }

  // Copy remaining elements from the right half
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  // Copy the merged elements back to the original array
  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

// MergeSort function (recursive)
void ms(vector<int> &arr, int low, int high) {
  if (low == high) return;  // Base case: when there's only one element
  int mid = (low + high) / 2;
  ms(arr, low, mid);         // Recursively sort the left half
  ms(arr, mid + 1, high);    // Recursively sort the right half
  merge(arr, low, mid, high); // Merge the two halves
}

int main() {
  vector<int> arr1 = {2, 2, 3, 5, 8, 1, 24, 512, 23};
  ms(arr1, 0, arr1.size() - 1);
  cout << "Sorted array (MergeSort): ";
  for (int e : arr1) {
    cout << e << " ";
  }
  cout << endl;

  vector<int> arr2 = {10, 7, 8, 9, 1, 5};
  qs(arr2, 0, arr2.size() - 1);
  cout << "Sorted array (QuickSort): ";
  for (int e : arr2) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}
