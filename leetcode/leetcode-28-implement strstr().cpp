#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    //方法1 暴力法
    int strStr(string haystack, string needle) {
        int i,j=0;
        int haystackLen = haystack.length();
        int needleLen   = needle.length();
        if(needleLen == 0) return 0;
        if(needleLen > haystackLen) return -1;
        for( i = 0; i < haystackLen - needleLen + 1; i++ ){
            //or haystack.compare( i, needleLen, needle ) == 0
            if( haystack.substr(i, needleLen) == needle )
                return i;
        }
        return -1;
    }
};
int main(){
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr(haystack, needle) << endl;

    return 0;
}
