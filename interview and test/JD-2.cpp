#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;



int main() {
    int n, m;
    int x, y;
    int res = 0;
    vector<int> leave;  // 存储需要出去的人的编号
    multimap<int, int> my_map;
    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        my_map.insert(pair<int, int> (x, y));  // 将关系存入 map 中
     }

    while(my_map.size() > 0){
        int t = my_map.begin()->first;
        res++;
        leave.push_back(t);
        while(my_map.size() > 0 && t == my_map.begin()->first){
            auto i = my_map.begin();
            my_map.erase(i);
        }
    }
    cout << res << endl;
    for(auto i : leave){
        cout << i << " ";
    }
    return 0;
}
