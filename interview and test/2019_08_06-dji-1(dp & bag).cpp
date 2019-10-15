#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

// 背包问题
// games_num : 游戏种类数 （类似物品种类）
// max_days  : 玩游戏的最大天数（类似背包最大承重）
// cost_day  : 玩每种游戏所需天数（类似每种物品的重量）
// score     : 玩每种游戏所得的分数（类似每种物品的价值）
// 求 在刚好玩了 max_days 后，所能得到的最高分数
// 类似求 在刚好装满背包的情况下，物品的价值最大
int calMaxScore(int games_num, int max_days, vector<int> &cost_day, vector<int> &score) {
    vector<vector<int> > res(games_num+1, vector<int>(max_days+1, 0)); // 用于记录每一步的结果，
                                                                       // res[i][j] 表示：前 i 个游戏，在所玩天数（即最大容量）为 j 时的最大价值。
    for(int i = 1; i <= games_num; i++) {       // 第 i 个游戏
        for(int j = 1; j <= max_days; j++) {    // 总玩的天数，即背包容量为 j
            if(cost_day[i] > j) {               // 当前游戏所花天数大于容量 j 时， 即当前背包的容量 j 放不下第 i 件商品时
                res[i][j] = res[i - 1][j];      // 当前容量 j 的最大成就值取上一个最大成就值，即最大价值
            } else {
                res[i][j] = max( res[i - 1][j - cost_day[i]] + score[i], res[i - 1][j] ); //
            }
        }
    }

    return res[games_num][max_days];
}


int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, X;
        cin >> N >> X;
        vector<int> cost_day(N+1, 0);  // weight
        vector<int> scores(X+1, 0);  // value
        for(int i = 1; i <= N; i++) {
            int a, b;
            cin >> a >> b;
            scores[i] = a;
            cost_day[i] = b;
        }
        cout << calMaxScore(N, X, cost_day, scores);
    }
    return 0;
}
