#include<iostream>
#include<vector>
using namespace std;

// n 个包子，各自拥有 美味度 和 美味度下降速度 两个属性，
// 每天，大雄偷吃最美味的两个，当美味度一样时吃下降速度最大的那个，此时包子美味度变为 -1
// 然后包子美味度下降，小于等于0时就不能吃了。
// 然后哆啦A梦检查，当美味的包子小于 m 个时，发怒，结束。
// 输出最后各个包子的美味度

// 代码仍需完善，只通过 20%

void run(vector<pair<int, int>> &food, int m){
    int amount = food.size(); // 剩余可吃数量
    if(amount < 1) return;
    if(amount == 1){
        food[0].first = -1;
        return;
    }
    int cur_max_dgree1 = 0;  // 当前美味度最大的豆沙包的下标
    int cur_max_dgree2 = 1;  // 当前美味度次大的豆沙包的下标

    while(amount){
        int food_size = food.size();
        for(int i = 0; i < food_size; ++i){ // 寻找美味度最大的两个豆沙包的下标
            if(food[i].first > 0 && i != cur_max_dgree1 && i != cur_max_dgree2 && food[i].first >= food[cur_max_dgree1].first){ // 美味度大于等于当前最大的美味度1
                if(food[i].first == food[cur_max_dgree1].first && food[i].second > food[cur_max_dgree1].second){// 等于时，需要下降速度更大才需更改
                    cur_max_dgree1 = i;
                }else if(food[i].first > food[cur_max_dgree1].first){
                    cur_max_dgree1 = i;
                }
            }
            if(food[i].first > 0 && i != cur_max_dgree1 && i != cur_max_dgree2 && food[i].first >= food[cur_max_dgree2].first){ // 美味度大于等于当前最大的美味度2
                if(food[i].first == food[cur_max_dgree2].first && food[i].second > food[cur_max_dgree2].second){// 等于时，需要下降速度更大才需更改
                    cur_max_dgree2 = i;
                }else if(food[i].first > food[cur_max_dgree2].first){
                    cur_max_dgree2 = i;
                }
            }
        }
        // 大雄吃掉两个包
        if(food[cur_max_dgree1].first)
            food[cur_max_dgree1].first = -1;
        if(food[cur_max_dgree2].first)
            food[cur_max_dgree2].first = -1;

        // 包子美味度下降
        for(int i = 0; i < food_size; ++i ){
            if(food[i].first != -1){
                food[i].first -= food[i].second;
                if(food[i].first <= 0){
                    food[i].first = 0;
                }
            }

        }

        // 哆啦A梦检查包子
        for(int i = 0; i < food_size; ++i){
            if(food[i].first <= 0){
                --amount;
            }
        }

        if(amount < m){ // 发怒
            return;
        }
    }
}

int main() {
    int n, m;
    int amount; // 剩余可吃豆沙包数量
    vector<pair<int, int>> food;
    cin >> n >> m;
    while(n--){
        int dgree, speed; // 美味度和下降速度
        cin >> dgree >> speed;
        food.push_back({dgree, speed});
    }
    run(food, m);

    for(int i = 0; i < food.size(); ++i){
        cout << food[i].first << endl;
    }
    return 0;
}
