#include<iostream>
#include<string>
using namespace std;

/*给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int carry=0, sum;
        int i=a.length()-1, j=b.length()-1;
        while( i >= 0  || j >= 0 || carry ){
            char c;
            int x=0, y=0;
            if( i >= 0) x = a[i--]-'0';
            if(j >= 0) y = b[j--]-'0';
            sum= x + y +carry;
            c = '0' + sum%2;
            res = c + res;
            carry = sum/2;
        }
        return res;
    }
};
int main(){
    Solution s;
    char a[128], b[128];
    while(scanf("%s %s", a, b) == 2){
    	cout << s.addBinary(a, b) << endl;
	}

    return 0;

}

