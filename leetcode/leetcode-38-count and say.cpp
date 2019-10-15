#include<iostream>
#include<string>
using namespace std;
//
//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.


class Solution{
public:
    string countAndSay(int n){

        char currentNum;
        int numCount;
        string res[n];
        res[0] = "1";
        for(int i=1; i<n; i++){
            // 初始化
            currentNum = res[i-1][0];
            numCount = 0;
            res[i] = "";
            // 遍历上一个字符串，统计数字个数并存下当前报数
            for(int j=0; j<res[i-1].size(); j++){
                if(res[i-1][j] == currentNum){
                    numCount++;
                }else{
                    res[i] += '0' + numCount;
                    res[i] += currentNum;
                    currentNum = res[i-1][j];
                    numCount = 0;
                    j--;
                }
                // 加上最后的统计，也可放在循环外部
                if( j == res[i-1].size()-1){
                    res[i] += '0'+numCount;
                    res[i] += currentNum;
                    numCount = 0;
                }
            }
            //cout << res[i] << endl;

        }
        return res[n-1];
    }
};
int main(){
    Solution s;
    cout << s.countAndSay(20) << endl;
    return 0;
}
