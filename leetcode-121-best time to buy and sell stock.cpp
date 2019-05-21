#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int len = prices.size();
        if(len == 0) return 0;
        int minPrice = prices[0];
        for(int i = 1; i < len; i++){
            if( prices[i] - minPrice > profit ){
                profit = prices[i] - minPrice;
            }else if( prices[i] < minPrice){
                minPrice = prices[i];
            }
        }
        return profit;
    }
};
int main(){
    Solution s;
    vector<int> prices = {};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
