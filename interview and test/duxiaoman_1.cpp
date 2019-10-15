#include<iostream>
#include<vector>
using namespace std;

// 计算至少需要多少次技能
int calSkillTimes(vector<int> &blood){
    int len = blood.size();
    int minSkillTimes = 0;
    for(int i = 1; i < len; i++){
        int maxtimes = 0;
        if( 2*i < len && 2*i+1 < len){ // 3个格子都在地图上
            maxtimes = max(blood[i], max(blood[2*i], blood[2*i+1]));
            if(maxtimes > 0){
                minSkillTimes += maxtimes;
                blood[i] -= maxtimes;
                blood[2*i] -= maxtimes;
                blood[2*i+1] -= maxtimes;
            }
        }else if(2*i < len && 2*i+1 >= len){ // 只有2个格子都在地图上
            maxtimes = max(blood[i], blood[2*i]);
            if(maxtimes > 0){
                minSkillTimes += maxtimes;
                blood[i] -= maxtimes;
                blood[2*i] -= maxtimes;
            }
        }else if(2*i >= len && 2*i+1 >= len && blood[i] > 0){ // 只有1个格子在地图上
            minSkillTimes += blood[i];
            blood[i] -= maxtimes;
        }
        //cout << "i " << i << " max: " << maxtimes << endl;
    }
    return minSkillTimes;
}

int main(){
    int n;
    cin >> n;  // 地图大小
    vector<int> blood(n + 1, 0);  // 地图上敌人的血量
    for(int i = 1; i <= n; i++){
        cin >> blood[i];
        //cout << blood[i];
    }
    cout << calSkillTimes(blood) << endl;
    return 0;
}
