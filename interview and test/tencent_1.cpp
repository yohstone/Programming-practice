#include<iostream>
#include<string>
using namespace std;

bool isGoodPhoneNumber(string str, int strLen){
    if(strLen < 11){
        return false;
    }
    auto posOfFirst8 = str.find("8");
    cout << "find res :" << posOfFirst8 << endl;
    if(posOfFirst8 == string::npos){
        return false;
    }
    int leftLen = strLen - posOfFirst8;  // 第一个 '8' 之后的长度
    return leftLen >= 11;
}

int main(){
    int t;  // 测试用例数量
    cin >> t;
    while(t--){
        int n;  // 每个用例字符串的长度
        string s;
        cin >> n;
        cin >> s;
        if(isGoodPhoneNumber(s, n)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
