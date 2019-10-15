#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void grouping(vector<int> &power){
    int group1Power = 0;
    int group2Power = 0;
    int len = power.size();
    for(int i = 0; i < len/2; i++){
        if(i % 2 == 0){
            group1Power = group1Power + power[i] + power[len - i - 1];
        }else{
            group2Power = group2Power + power[i] + power[len - i - 1];
        }
    }
    if(group1Power < group2Power){
        cout << group1Power << " " << group2Power << endl;
    }else{
        cout << group2Power << " " << group1Power << endl;
    }
}

int main(){
    int t;  // 测试用例数量
    cin >> t;
    while(t--){
        int n;  // 员工数量
        vector<int> power;
        cin >> n;
        while(n--){
            int tmp;
            cin >> tmp;
            power.push_back(tmp);
        }
        sort(power.begin(), power.end());
        grouping(power);
    }
}
