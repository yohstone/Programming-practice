#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 统计字符串 S 中 包含多少个子串 T
void countSubstr(string S, string T, vector<int> &countRes){
    string substrOfS;
    int count = 0;
    int len1 = S.size();
    int len2 = T.size();
    int lastPos = -1;    // 上一个子串的位置
    for(int i = 1; i <= len1; i++){
        substrOfS = S.substr(0, i);
        //cout << "substr:" << substrOfS << endl;
        auto findRes = substrOfS.rfind(T);
        //cout << "fing begin :" << findBegin << endl;
        //cout << "findRes : " << findRes << "  lastPos: " << lastPos << endl;
        if(findRes != string::npos && findRes != lastPos){
            lastPos = findRes;
            //findBegin = findBegin + len2;
            ++count;
        }
        countRes[i] = count;
    }
}


int main(){
    string S, T;
    cin >> S;
    cin >> T;
    vector<int> countRes(S.size()+1, 0); // 用于输出的统计结果
    countSubstr(S, T, countRes);
    for(int i = 1; i < countRes.size(); i++){
        cout << countRes[i] << ' ';
    }
    cout << endl;
}
