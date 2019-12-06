#include<iostream>
#include<vector>
using namespace std;


// 输入 n 对温度采样值，和需覆盖值 k
// 求 n 对温度采样值中满足覆盖值最少为 k 的最低可信温度和最高可信温度


vector<int> findTrustedTem(vector<pair<int, int>> &nums, int k){
    int len = nums.size();
    vector<int> res(2, 0);
    if(len == 0) return res;
    int Tmin = 100;
    int Tmax = -100;

    for(int i = 0; i < len - 1; ++i){
        int cur_min = nums[i].first;
        int cur_max = nums[i].second;
        int cur_min_count = 0;
        int cur_max_count = 0;
        for(int j = 0; j < len; ++j ){
            if(cur_min >= nums[j].first && cur_min <= nums[j].second){
                ++cur_min_count;
            }
            if(cur_max >= nums[j].first && cur_max <= nums[j].second){
                ++cur_max_count;
            }
        }
        if(cur_min < Tmin && cur_min_count >= k){
            Tmin = cur_min;
        }
        if(cur_max > Tmax && cur_max_count >= k){
            Tmax = cur_max;
        }
    }
    res[0] = Tmin;
    res[1] = Tmax;
    return res;
}

int main() {
    int n, k;
    vector<pair<int, int>> nums;
    cin >> n >> k;
    while(n--){
        int low_i, high_i;
        cin >> low_i >> high_i;
        nums.push_back({low_i, high_i});
    }
    vector<int> res = findTrustedTem(nums, k);
    if(res[0] == 100 || res[1] == -100){
        cout << "error" << endl;
    }else{
        cout << res[0] << ' ' << res[1] << endl;
    }

    return 0;
}
