#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);
 */


class Solution {
public:
    // 方法1： 照要求将字符串以Z字形放入容器中，然后再拼接出结果
    string convert(string s, int numRows) {
        int sLen = s.size();
        if(sLen <= 2 || numRows == 1){
            return s;
        }
        int currRow = 0;
        bool goingDown = false;                             // 方向标志位 true：方向向下，行+1； false：方向斜向上，行-1
        vector<string> convertArr(min(numRows, sLen));      // 使用min防止有空行

        for(int i = 0; i < sLen; i++ ){                     // 以Z字形将字符串放入vector容器中
            convertArr[currRow] += s[i];
            cout << convertArr[currRow] << endl;
            if( currRow == numRows-1 || currRow == 0 ){
                goingDown = !goingDown;
            }
            if(goingDown){
                currRow++;
            }else{
                currRow--;
            }
        }
        string res = "";
        for(int i = 0; i < convertArr.size(); i++){
            res += convertArr[i];
        }
        return res;
    }

/*    方法2： 找规律，令 n = numRows， row为Z字形结果矩阵的行号
 *            每一行字符下标 i 间差值的规律为：
 *            首尾两行： interval = 2*n - 2
 *            中间行：interval = 2*n - 2 - 2*row 或  interval = 2*row
 */

    string convert2(string s, int numRows) {
        int sLen = s.size();
        if(sLen <= 2 || numRows == 1){
            return s;
        }

        string res = "";
        for(int currRow = 0; currRow < numRows; currRow++){
            int interval;
            int firstInterval = (2 * numRows - 2) - 2 * currRow; // 避免重复计算
            int secondInterval = 2 * currRow;                    // 避免重复计算
            bool isFirst = true;                                 // 用于区分interval取何值，true：取firstInterval; false：取secondInterval;
            int index = currRow;

            while( index < sLen ){
                interval = isFirst ? firstInterval : secondInterval;
                if( interval == 0 ){                             // 跳过首尾两行有个interval为0的情况
                    isFirst = !isFirst;
                    continue;
                }
                res += s[index];
                index += interval;
                isFirst = !isFirst;
            }
        }
        return res;

    }


};

int main(){
    Solution s;
    string str = "LEETCODEISHIRINGHAHAHA";//"pqwuzifwovyddwyvvbu";
    int numRows = 5;

    cout << s.convert2(str, numRows) << endl;
    return 0;
}
