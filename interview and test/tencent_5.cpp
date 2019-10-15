#include<iostream>
using namespace std;

int main(){
    while(1){
        long n;      // 非负整数序列的长度
        long tmp;
        long res1 = 0;
        long res2 = 0;
        cin >> n;
        tmp = n;
        while(tmp--){
            long a;
            cin >> a;
            res1 = res1 ^ a;
        }
        while(n--){
            long b;
            cin >> b;
            res2 = res2 ^ b;
        }
        long res = res1 ^ res2;
        cout << res << endl;
    }

    return 0;
}
