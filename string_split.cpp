#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

// 输入为 分隔符 d1 d2 带分割字符串 s
// 输出为使用 d1 d2 分割 s 后的字符串
// 如 输入： "# : a:3#b:8#c:9";
// 输出：
// a 3
// b 8
// c 9


int main() {
    // char test[] = "# : a:3#b:8#c:9";
    string d1, d2; // 分隔符
    string s;      // 待分割字符串
    cin >> d1 >> d2 >> s;
    vector<char*> substrs;    // 保存切割后的字符串
    char p1[s.size() + 1]; // 将 string 转换成 char * ， 或用 = new char[s.size() + 1];
    strcpy(p1, s.c_str());

    char *substr_p = strtok(p1, d1.c_str());    // 使用 d1 分割字符串，将结果保存到 substrs 中
    while(substr_p != nullptr ){
        substrs.push_back(substr_p);
        substr_p = strtok(nullptr, d1.c_str());

    }
    for(int i = 0; i < substrs.size(); i++){    // 使用 d2 分割 substrs 中的字符串并输出
        char *substr_p2 = strtok(substrs[i], d2.c_str());
        while(substr_p2 != nullptr ){
            cout << substr_p2 << ' ';
            substr_p2 = strtok(nullptr, d2.c_str());
        }
        cout << endl;
    }
    return 0;
}

