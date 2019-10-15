#include<iostream>
#include<vector>
using namespace std;
int calBuyNum(vector<int> &favorite_drinks, int worker_nums, int drink_types){
    int len = favorite_drinks.size();
    int res = 0;  // 购买瓶数
    for(int i = 1; i < len; i++){
        if(favorite_drinks[i] >= 2){
            res = res + (favorite_drinks[i] / 2) + (favorite_drinks[i] % 2);
        }else{
            res = res + favorite_drinks[i];
        }
        cout << "res: " << res << " f_d : " << favorite_drinks[i] << " len :" << len << endl; 
    }
    return res;
}
int main(){
    int n, k;  // n 名员工， k 种果汁
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        a[ai]++;
        cout <<" ai: " << i << " count:" <<  a[ai] << endl;  
    }
    cout << calBuyNum(a, n, k) << endl;
    return 0;
}
