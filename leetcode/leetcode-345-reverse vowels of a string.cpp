#include<iostream>
#include<set>

using namespace std;

/* Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 *
 * Input: "hello"
 * Output: "holle"
 * Example 2:
 *
 * Input: "leetcode"
 * Output: "leotcede"
 * Note:
 * The vowels does not include the letter "y".
 */


class Solution {
public:
    // 方法：用头尾指针 i 和 j 分别从两头寻找元音字母，i 和 j 都找到元音字母后互相交换，然后继续遍历
    string reverseVowels(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            while(!(vowels.find(s[i]) != vowels.end()) && i < j){
                i++;
            }
            while( i < j && !(vowels.find(s[j]) != vowels.end()) ){
                j--;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main() {
    return 0;
}
