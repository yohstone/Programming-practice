#include<iostream>
#include<string>
using namespace std;

/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * Example:
 *
 * Input: "Hello World"
 * Output: 5
 */


class Solution{
public:
    // 方法1 ：从头遍历，遇到空格则存储刚结束的单词的长度，若遇到新单词则重新开始算长度，否则返回存储的长度
    int lengthOfLastWord(string s){
        int length = 0;     // 当前单词长度
        int preLength = 0;  // 上一个单词长度
        int flag = 0;       // 用于记录前一个字符是否为空格
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' ' && flag == 0 ){
                flag = 1;
                preLength = length;
                length = 0;
            }else if( s[i] != ' ' ){
                flag = 0;
                length++;
            }
        }
        // 若结尾是空格，返回preLength， 若不是空格，返回length
        if( flag ){
            return preLength;
        }else{
            return length;
        }
    }

    // 方法2：从后遍历，计算完第一个单词后遇到空格返回单词长度
    int lengthOfLastWord2(string s){
        int length = 0;  // 当前单词长度
        int flag = 0;    // 是否是计算完最后一个单词后遇到空格,0否，1是

        for(int i=s.length()-1; i>=0; i--){
            if( s[i] != ' ' ){
                flag = 1;
                length++;
            }else if( s[i] == ' '  && flag == 1){
                return length;
            }
        }
        return length;
    }
};
int main(){
    Solution s;
    string str = "hello world!";
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}
