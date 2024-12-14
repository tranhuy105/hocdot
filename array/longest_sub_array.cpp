#include <bits/stdc++.h>
using namespace std;

/*
Đề bài:
Viết một chương trình để tìm độ dài của dãy con (subarray) dài nhất có tổng bằng `K` trong một mảng số nguyên.

Yêu cầu:
- Một dãy con (subarray) là một đoạn liên tiếp trong mảng.
- Tìm độ dài lớn nhất của dãy con sao cho tổng của các phần tử trong dãy con đó bằng `K`.

Đầu vào:
- Một số nguyên `N` đại diện cho độ dài của mảng.
- Một số nguyên `K` là tổng mục tiêu.
- Một mảng số nguyên `A` có độ dài `N`.

Đầu ra:
- Một số nguyên biểu thị độ dài của dãy con dài nhất có tổng bằng `K`.

Ví dụ:
- Input: A = {-1, 2, 3}, N = 3, K = 6
- Output: 2 (dãy con dài nhất là {2, 3})

Ghi chú:
- Mảng có thể chứa cả số dương và số âm.
- Nếu không tìm được dãy con nào có tổng bằng `K`, trả về 0.
*/


// O(n^2)
int lenOfLongSubarr1(int A[],  int N, int K) 
{ 
    int sum;
    int max = 0;
    for (int i=0;i<N;++i) {
        sum = 0;
        for (int j=i; j<N;++j) {
            sum += A[j];
            if (sum == K) {
                max = std::max(max, j-i+1);
            }
        }
    }

    return max;
} 

// O(NlogN)
int lenOfLongSubarr2(int A[],  int N, int K) 
{ 
    map<long, int> sumPrefix;
    long sum = 0;
    int maxLen = 0;
    for (int i=0;i<N;++i) {
        sum += A[i];
        if (sum == K) {
            maxLen = max(maxLen, i+1);
        }
        
        long requiredSum = sum - K;
        if (sumPrefix.find(requiredSum) != sumPrefix.end()) {
            int len = i - sumPrefix[requiredSum];
            maxLen = max(maxLen, len);
        }

        // Only store the first occurrence of the prefix sum
        if (sumPrefix.find(sum) == sumPrefix.end()) {
            sumPrefix[sum] = i;
        }
    } 

    return maxLen;
} 

// O(2n) - 2 pointer (if all element >= 0);
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    int left = 0, right = 0;
    long sum = A[0];
    int maxLen = 0;
    while (right < N) {
        while (left <= right && sum > K) {
            sum -= A[left];
            left++;
        }

        if (sum == K) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < N) sum += A[right];

    }
    return 1;
} 


int main() {
    int n = 3, arr[] = {-1,2,3}, k = 6;
    std::cout << lenOfLongSubarr(arr, n, k) << std::endl;
    return 0;
}