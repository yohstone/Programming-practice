#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int len = prices.size();
        for(int i = 1; i < len; i++){
            if( prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};
int main(){
    Solution s;
    vector<int> prices = {1,2,3,4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
