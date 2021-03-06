#include<iostream>
#include<vector>
using namespace std;

//    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
//    如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//
//    注意你不能在买入股票前卖出股票。
//
//    示例 1:
//
//    输入: [7,1,5,3,6,4]
//    输出: 5
//    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//         注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
//    示例 2:
//
//    输入: [7,6,4,3,1]
//    输出: 0
//    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//
//    Say you have an array for which the ith element is the price of a given stock on day i.
//
//    If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//    Note that you cannot sell a stock before you buy one.
//
//    Example 1:
//
//    Input: [7,1,5,3,6,4]
//    Output: 5
//    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//                 Not 7-1 = 6, as selling price needs to be larger than buying price.
//    Example 2:
//
//    Input: [7,6,4,3,1]
//    Output: 0
//    Explanation: In this case, no transaction is done, i.e. max profit = 0.



class Solution {
public:
    // 存下最小的股票价格和最大利润，遍历数组计算最大利润
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int len = prices.size();
        if(len == 0)
            return 0;
        int min_price = prices[0];
        for(int i = 1; i < len; i++) {
            if( prices[i] - min_price > max_profit ) {
                max_profit = prices[i] - min_price;
            } else if( prices[i] < min_price) {
                min_price = prices[i];
            }
        }
        return max_profit;
    }
};
int main() {
    Solution s;
    vector<int> prices = {};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
