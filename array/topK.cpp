#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
Đề bài:
Viết một chương trình để tìm `k` phần tử xuất hiện nhiều nhất trong một mảng số nguyên.

Yêu cầu:
- Trả về danh sách các phần tử có tần suất xuất hiện cao nhất theo thứ tự bất kỳ.
- Đảm bảo chương trình hoạt động tối ưu về thời gian và không gian.

Đầu vào:
- Một vector số nguyên `nums`.
- Một số nguyên `k` (số lượng phần tử cần tìm).

Đầu ra:
- Một vector chứa `k` phần tử xuất hiện nhiều nhất trong `nums`.

Ví dụ:
- Input: nums = {1, 1, 1, 2, 2, 3}, k = 2
- Output: {1, 2} (phần tử 1 xuất hiện 3 lần, phần tử 2 xuất hiện 2 lần)

Phương pháp:
1. **Min-Heap**:
   - Dùng `unordered_map` để đếm tần suất xuất hiện của mỗi phần tử.
   - Dùng `priority_queue` để duy trì top `k` phần tử có tần suất cao nhất.
   - Độ phức tạp: O(n log k).

2. **Bucket Sort**:
   - Dùng `unordered_map` để đếm tần suất xuất hiện của mỗi phần tử.
   - Tạo một mảng con (bucket) để nhóm các phần tử theo tần suất.
   - Duyệt từ tần suất cao nhất đến thấp nhất để lấy top `k` phần tử.
   - Độ phức tạp: O(n).

*/


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < nums.size(); i++) {
        frequencyMap[nums[i]]++;
    }

    auto comp = [&](int a, int b) {return frequencyMap[a] > frequencyMap[b];};
    priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

    for (const auto& [num, freq] : frequencyMap) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> topKElements;
    while (!minHeap.empty()) {
        topKElements.push_back(minHeap.top());
        minHeap.pop();
    }

    return topKElements;
}

vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    for (int i = 0; i < nums.size(); i++) {
        frequencyMap[nums[i]]++;
    }

    int n = nums.size();
    vector<vector<int>> bucket(n+1);

    for (const auto& [num, frequency] : frequencyMap) {
        bucket[frequency].push_back(num);
    }

    vector<int> ans;
    for (int i = n; i >= 0; i--) {
        for (int it : bucket[i]) {
            ans.push_back(it);
            if (ans.size() == k) return ans;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequentBucketSort(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}