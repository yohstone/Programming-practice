#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int N;
    unordered_map<int, int> workers;
    cin >> N;
    cout << workers.max_size()<< endl;
    while(N--){
        int years;
        cin >> years;
        auto ret = workers.insert( {years, 100} ); // 初始化为 100
        cout << ret.first->first << " " << ret.first->second << endl;
    }
    int sum = 0;
    auto cur_iter  = workers.begin();
    auto next_iter = workers.begin();
    auto pre_iter = cur_iter;
    next_iter++;
    cout << cur_iter->first << endl;
    for(; cur_iter != workers.end(); cur_iter++){

        if(cur_iter == workers.begin()){  // 第一个员工
            cout << next_iter->first << " " << cur_iter->first << endl;
            if(next_iter->first < cur_iter->first){
                cur_iter->second = 200;
            }
            if(next_iter != workers.end())
                next_iter++;
        }else if(next_iter == workers.end()){ // 最后一个员工
            if(cur_iter->first > pre_iter->first){
                cur_iter->second = pre_iter->second + 100;
            }
        }else{                          // 中间员工
            if(cur_iter->first > pre_iter->first){
                cur_iter->second = pre_iter->second + 100;
            }
            if(next_iter != workers.end())
                next_iter++;
        }
        pre_iter = cur_iter;
        cout << cur_iter->second << endl;
        sum += cur_iter->second;

    }
    cout << sum << endl;
    return 0;
}
