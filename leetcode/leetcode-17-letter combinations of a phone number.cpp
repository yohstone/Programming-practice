#include<iostream>
using namespace std;

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//说明:
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
//
//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//
//Although the above answer is in lexicographical order, your answer could be in any order you want.



class Solution {
public:
    map<char, string> numberToLetter = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    // 方法1：递归实现，回溯法
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> res;
        string currString = "";
        letterCombinations(digits, res, currString);
        return res;

    }
    // 方法1的递归函数
    void letterCombinations(const string &digits, vector<string> &res, string &currString){
        if(currString.size() == digits.size()){
            res.push_back(currString);
        }else{
            for(auto c : numberToLetter[digits[currString.size()]]){ // 遍历当前数字对应的字母组合
                currString.push_back(c);
                letterCombinations(digits, res, currString);         // 尝试当前数字的每种对应情况
                currString.pop_back();
            }
        }
    }
};
int main(){

    return 0;
}
