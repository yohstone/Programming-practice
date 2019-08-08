#include<iostream>
#include<string>
using namespace std;

/**
 * 网易2020校园招聘模拟笔试 - 3
 *  由于失误，整数 N 的 X 进制和 Y 进制连在一起输出了，请识别出这个整数 N 的十进制值
 *  N 的最大值小于 2^31 - 1， 2 <= X, Y <= 16
 * 思路：
 * 使用二分法寻找两种进制的“中位数”，每次寻找都将左右两个子串转换成对应的进制数，然后进行比较。
 */

// 进制转换函数， 将 k 机制字符串转换为十进制数
long long kToDec(int k, string str){
    int len = str.size();
    long long res = 0;
    for(int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'F'){
            res = res * k + (str[i] - 'A') + 10;
        }else{
            res = res * k + (str[i] - '0');
        }
    }
    return res;
}

// 识别数字函数，返回识别结果
long long identifyNum(int x, int y, string str){
    int len  = str.size();
    int left = 0;
    int right = len - 1;
    while(left < right ){           // 使用二分法寻找两种进制的“中位数”
        int median = (left + right) / 2;
        long long num1   = kToDec(x, str.substr(0, median + 1)); // 左子串转换成十进制
        long long num2   = kToDec(y, str.substr(median + 1));    // 右子串转换成十进制
        if(num1 < num2){
            left = median + 1;
        }else if(num1 > num2){
            right = median;
        }else{
            return num1;
        }
    }
    return -1;
}

int main(){
    int T;          // 样例数
    cin >> T;
    while(T--){
        int X, Y;   // X 进制，Y 进制，
        string Z;   // 为数字字符串
        cin >> X >> Y >> Z;   // 最大输入示例：2 16 11111111111111111111111111111111FFFFFFFF
        cout << identifyNum(X, Y, Z) << endl;
    }
	return 0;
}





