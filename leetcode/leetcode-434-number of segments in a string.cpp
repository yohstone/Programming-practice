#include<iostream>
#include<string>
using namespace std;

/* Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 */


class Solution{
public:
    int countSegments(string s){
        int count = 0;
        bool lastIsWord = false;  // 之前是否遇到了单词
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                if(lastIsWord){
                    count++;
                }
                lastIsWord = false;
            }else{
                lastIsWord = true;
            }
        }
        if(lastIsWord){ // 最后一个子串是单词而不是空格的时候
            count++;
        }
        return count;
    }
};

int main(){

}
