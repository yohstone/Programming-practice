#include<iostream>
#include<vector>
using namespace std;

//    复原 IP 地址
//
//    给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//    示例:
//
//    输入: "25525511135"
//    输出: ["255.255.11.135", "255.255.111.35"]
//
//    Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//    Example:
//
//    Input: "25525511135"
//    Output: ["255.255.11.135", "255.255.111.35"]



class Solution {
public:
    // 方法1： 暴力法，枚举3个 '.' 的所有情况，将有效的插入结果数组中
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        if(len < 4 || len > 12)
            return res;
        for(int i = 1; i <= 3; ++i){
            for(int j = i + 1; j <= 6 && j < len; ++j){
                for(int k = j + 1; k <= 9 && k < len; ++k){
                    string sub_str1 = s.substr(0, i);
                    string sub_str2 = s.substr(i, j - i);
                    string sub_str3 = s.substr(j, k - j);
                    string sub_str4 = s.substr(k);
                    if(isValid(sub_str1) && isValid(sub_str2) && isValid(sub_str3) && isValid(sub_str4)){
                        string str_tmp = sub_str1 + '.' + sub_str2 + '.' + sub_str3 + '.' + sub_str4;
                        res.push_back(str_tmp);
                    }
                }
            }
        }
        return res;
    }
    // 判断该段数字是否在 0 ~ 255 内
    bool isValid(string &str){
        if((str[0] == '0' && str.size() > 1 ) || str.size() == 0){ // 防止出现 012,  022等情况
            return false;
        }
        int val = stoi(str);
        if(val >= 0 && val <= 255){
            return true;
        }else{
            return false;
        }
    }


    // 方法2 ： 回溯法,dfs
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.size();
        if(len < 4 || len > 12)
            return res;
        dfs(s, "", 0, 0, res);
        return res;
    }
    // 递归函数
    void dfs(string &s, string cur_str, int cur_index, int cur_segment, vector<string> &res){
        int len = s.size();
        if(len - cur_index > 3 * (4 - cur_segment)){  // 如果剩余的长度大于剩下的部分的最大长度（都取 3 位数），那么直接结束

            return;
        }

        if(cur_index == len){           // 已经遍历完字符串 s
            if(cur_segment == 4){       // 且第4段也已经处理完
                res.push_back(cur_str.substr(0, cur_str.size() - 1)); // 插入结果数组中
            }
            return ;
        }
        if(cur_index > len || cur_segment == 4){ // 4段都处理完了字符串a还有剩余，直接结束
            return;
        }

        for(int i = 1; i <= 3 && cur_index + i <= len; ++i){
            string sub_str = s.substr(cur_index, i);
            int val = stoi(sub_str);

            if(sub_str[0] == '0' && i > 1){  // 防止出现 012,  022等情况
                return ;
            }else if(val >= 0 && val <= 255){
                dfs(s, cur_str + sub_str + '.', cur_index + i, cur_segment + 1, res);
            }
        }
    }
};


int main(){

	return 0;
}
