#include<iostream>
#include<vector>
using namespace std;

// 有 n 种硬币，面值分别为 V1, V2, ..., Vn，每种无限多，给定非负整数 S，
// 可以选用多少硬币，使得面值之和恰好为 S，输出硬币数目的最小值
// ( 1 <= n <= 100, 0 <= S <= 10000, 1 <= Vi <= S )

// coin_types : 硬币种类数量   coin_value ：每种硬币的面值数组    max_sum ：面值之和（或称为支付金额）
// dp[i][j] : 第 0 到 第 i 种硬币支付 j 元时的最少硬币数
int calMinCionNum(int coin_types, vector<int> &coin_value, int max_sum){
    vector<vector<int>> dp(coin_types+1, vector<int> (max_sum + 1, 0));
    for(int i = 1; i <= coin_types; i++){
        for(int j = 1; j <= max_sum; j++){
            if(coin_value[i] > j){    // 如果 coin_value[i] > j， j-coin_value[i] 会导致访问越界，同时也表示硬币 i 面值太大已经超过 j，不需要用于计算
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = min( dp[i-1][j], dp[i][ j-coin_value[i] ] + 1 );
            }
        }
    }
    return dp[coin_types][max_sum];
}

int main() {
    int n, m;
    int x, y;

    return 0;
}
