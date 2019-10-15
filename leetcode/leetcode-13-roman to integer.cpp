#include<iostream>
#include<map>
#include<string>
using namespace std;

/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 *
 * Example 1:
 *
 * Input: "III"
 * Output: 3
 * Example 2:
 *
 * Input: "IV"
 * Output: 4
 * Example 3:
 *
 * Input: "IX"
 * Output: 9
 * Example 4:
 *
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * Example 5:
 *
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */


class Solution {
public:

	//方法1，使用map存储罗马数字对应的十进制值，直接遍历字符串进行转换
    int romanToInt(string s) {
        map<char, int> roman;
        int sum = 0, len = s.length();
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        for(int i=0; i<len; i++){
        	if( roman[s[i]] < roman[s[i+1]]){  // 判断下一个罗马数字是否比当前的大，是则需要减去当前值
        		sum = sum - roman[s[i]];
			}else{
				sum = sum + roman[s[i]];
			}
		}
		return sum;
    }
    //方法2，总结所有情况，使用多个if判断转换方式，执行效率较高
    int romanToInt2(string s) {
    	int sum = 0, len = s.length();
        for(int i=0; i<len; i++){
        	if( s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X' ) ){         // 有4和9的情况
        		sum = sum - 1;
			}else if( s[i] == 'I'){
				sum = sum + 1;
			}else if( s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){     // 有40和90的情况
				sum = sum - 10;
			}else if( s[i] == 'X'){
				sum = sum + 10;
			}else if( s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){     // 有400和900的情况
				sum = sum - 100;
			}else if( s[i] == 'C'){
				sum = sum + 100;
			}else if( s[i] == 'V'){
				sum = sum + 5;
			}else if( s[i] == 'L'){
				sum = sum + 50;
			}else if( s[i] == 'D'){
				sum = sum + 500;
			}else if( s[i] == 'M'){
				sum = sum + 1000;
			}
		}
		return sum;
    }
};
int main(){
	Solution s;
	string str;

	while(cin >> str){
		cout << s.romanToInt2(str) << endl;
	}

	return 0;
}
