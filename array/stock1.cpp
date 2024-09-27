#include <iostream>
#include <vector>
#include <limits.h>

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = INT_MIN;
    for (int i = 0; i < prices.size(); i++) {
        int buyPrice = prices[i];
        for (int j = i + 1; j < prices.size(); ++j) {
            int profit = prices[j] - buyPrice;
            maxProfit = max(profit, maxProfit);
        }
    }

    return max(0,maxProfit);
}

int maxProfit1(vector<int>& prices) {
    int maxProfit = INT_MIN;
    int currentPriceToBuy = INT_MAX;
    for (int price : prices) {
        if (price < currentPriceToBuy) {
            currentPriceToBuy = price;
        }

        maxProfit = max(maxProfit, price - currentPriceToBuy);
    }

    return maxProfit;
}

int main() {
    vector<int> nums = {7,3,999,1,5,3,6,2,4,24,5,50};
    cout << maxProfit1(nums) << endl; 
    return 0;
}