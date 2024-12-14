#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int maxPiles = INT_MIN;

    for (int p : piles) {
        maxPiles = max(maxPiles, p);
    }

    int left = 1; int right = maxPiles;

    while (left <= right) {
        int candidate = left + (right - left) / 2;
        long long acc = 0;

        for (int p : piles) {
            acc += ceil((double)p / candidate);
        }

        // If we can finish within h hours, try a smaller speed
        if (acc <= h) {
            right = candidate - 1;
        } else {
            left = candidate + 1;
        }
    }

    return left;
}

int main() {
    vector<int> v = {3,6,7,11};
    cout << minEatingSpeed(v, 8) << endl;
    return 0;
}