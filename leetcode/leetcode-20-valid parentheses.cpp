#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int rear = 1;
        int len = s.length();
        char st[len+2];//stack
        for(int i=0; i < len; i++){
            if(s[i] == ')' && st[rear-1] != '('){
                return false;
            }else if(s[i] == ']' && st[rear-1] != '['){
                return false;
            }else if(s[i] == '}' && st[rear-1] != '{'){
                return false;
            }else if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
                st[rear++] = s[i];
            }else{
                rear--;
            }
        }
        if(rear == 1)
            return true;
        else
            return false;
    }
};
int main(){
    Solution s;
    string str;
    while(cin >> str){
        cout << s.isValid(str) << endl;
    }
    return 0;
}
