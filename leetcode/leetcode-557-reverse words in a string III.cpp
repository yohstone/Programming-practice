#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
    //�����ո�ͷ�ת֮ǰ�ĵ��ʣ�Ȼ��ƴ�ӵ�����ַ���֮��
    string reverseWords1(string s){
        int len = s.size();
        string temp = "", res = "";
        for( int i = 0; i <= len; i++ ){
            if( s[i] == ' ' || s[i] == '\0' ){
                reverse( temp.begin(), temp.end() );
                res += temp;
                res += s[i];//ƴ�ϼ����
                temp = "";
            }else{
                temp += s[i];
            }
        }
        return res;
    }


};
int main(){
    Solution s;
    string str = "Let's take LeetCode contest";
    cout << s.reverseWords(str) << endl;
    return 0;
}
