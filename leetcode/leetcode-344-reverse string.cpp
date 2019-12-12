#include<iostream>
#include<vector>
using namespace std;


//    编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//
//    不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//
//    你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
//
//    Write a function that reverses a string. The input string is given as an array of characters char[].
//
//    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
//    You may assume all the characters consist of printable ascii characters.
//
//    Example 1:
//
//    Input: ["h","e","l","l","o"]
//    Output: ["o","l","l","e","h"]
//    Example 2:
//
//    Input: ["H","a","n","n","a","h"]
//    Output: ["h","a","n","n","a","H"]



class Solution {
public:
    // 方法1：使用首尾指针交换首尾的字符
    void reverseString(vector<char>& s) {
        double len = s.size();

        for( int i = 0; i < len / 2.0; i++) { //中位数两边互换
            char temp ;
            temp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = temp;
        }
    }
};
int main() {
    vector<char> str = {};
    Solution s;
    s.reverseString(str);
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << endl;
    }

    return 0;
}
