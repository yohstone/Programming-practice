#include<iostream>
#include<string>
using namespace std;

/* Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
 *
 * Example 1:
 *
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * Example 2:
 *
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * Example 3:
 *
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * Example 4:
 *
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 */


class Solution {
public:
    // 最高4ms 打败 93%
    string numberToWords(int num) {
    	string single[]      = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
		string tenToTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		string tens[]        = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int cur_digit = 0;                            // 记录已转换的位数便于输出 hundred thousand Million Billion等单词
        int n = num;                                  // n 用来除，num用于统计原数位数

        string words = "";
        while(n){
    		if(cur_digit == 3 && n % 1000 != 0){      // 转换到千位且千位以下不为0时，在之前转换好的字符串前拼上 Thousand
    			words = "Thousand " + words;
			}else if(cur_digit == 6){
				if(num % 1000000 == 0){               // 百万位以下的位都是0
					words = "Million";
				}else if( n % 1000 != 0 ){            // 百万位以上的3位数不为0
					words = "Million " + words;
				}
			}else if( cur_digit == 9){
				if(num % 1000000000 == 0){            // 10亿位以下的数字都是0
					words = "Billion";
				}else{                                // 十亿位以上的数不为0
					words = "Billion " + words;
				}

			}

        	int temp = n % 1000;                                // 根据英文的规律，每次取3位进行转换
        	int cur_digit2 = 0;                                 // 记录遍历3位数时的当前位数
        	int one_num, two_num;                               // 分别表示一位数与两位数
        	two_num = temp % 100;                               // 取后两位用于判断
        	while(temp){
        		one_num = temp % 10;                            // one_num 取每一位数字
				if(two_num >=10 && two_num < 20){               // 10 ~ 19
					words = tenToTwenty[one_num] + " "+ words;  // 拼接十几
					two_num = 0;
					cur_digit2++;
					temp /= 10;
				}else if(cur_digit2 == 1 && one_num > 0){       // 十位上的数字非0，且two_num不是十几，即 20 ~ 99，先拼接十位的单词
					words = tens[one_num-2] + " " + words;
				}else if(cur_digit2 == 2 && one_num > 0 ){      // 百位上的数字非0
					words = "Hundred " + words;
					words = single[one_num] + " " + words;
				}else if(cur_digit == 0 && one_num > 0 ){       // 如果后两位是 01 ~ 09
					words = single[one_num]  + " " + words;
				}else if(one_num > 0){                          // 其余情况，如 32 的个位
					words = single[one_num] + " " + words;
				}
        		cur_digit2++;
        		temp /= 10;
			}
        	n /= 1000;
			if(n > 0){
				cur_digit += 3;
			}
		}

		if(words.empty()){
			words = "Zero";
		};
		words.erase(words.find_last_not_of(" ") + 1);
		return words;
    }
};
int main(){
	Solution s;
	int n;
	while(cin >> n){
		cout << s.numberToWords(n) << endl;
	}

	return 0;
}
