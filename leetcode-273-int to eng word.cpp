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
    // ���4ms ��� 93%
    string numberToWords(int num) {
    	string single[]      = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
		string tenToTwenty[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		string tens[]        = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int cur_digit = 0;                            // ��¼��ת����λ��������� hundred thousand Million Billion�ȵ���
        int n = num;                                  // n ��������num����ͳ��ԭ��λ��

        string words = "";
        while(n){
    		if(cur_digit == 3 && n % 1000 != 0){      // ת����ǧλ��ǧλ���²�Ϊ0ʱ����֮ǰת���õ��ַ���ǰƴ�� Thousand
    			words = "Thousand " + words;
			}else if(cur_digit == 6){
				if(num % 1000000 == 0){               // ����λ���µ�λ����0
					words = "Million";
				}else if( n % 1000 != 0 ){            // ����λ���ϵ�3λ����Ϊ0
					words = "Million " + words;
				}
			}else if( cur_digit == 9){
				if(num % 1000000000 == 0){            // 10��λ���µ����ֶ���0
					words = "Billion";
				}else{                                // ʮ��λ���ϵ�����Ϊ0
					words = "Billion " + words;
				}

			}

        	int temp = n % 1000;                                // ����Ӣ�ĵĹ��ɣ�ÿ��ȡ3λ����ת��
        	int cur_digit2 = 0;                                 // ��¼����3λ��ʱ�ĵ�ǰλ��
        	int one_num, two_num;                               // �ֱ��ʾһλ������λ��
        	two_num = temp % 100;                               // ȡ����λ�����ж�
        	while(temp){
        		one_num = temp % 10;                            // one_num ȡÿһλ����
				if(two_num >=10 && two_num < 20){               // 10 ~ 19
					words = tenToTwenty[one_num] + " "+ words;  // ƴ��ʮ��
					two_num = 0;
					cur_digit2++;
					temp /= 10;
				}else if(cur_digit2 == 1 && one_num > 0){       // ʮλ�ϵ����ַ�0����two_num����ʮ������ 20 ~ 99����ƴ��ʮλ�ĵ���
					words = tens[one_num-2] + " " + words;
				}else if(cur_digit2 == 2 && one_num > 0 ){      // ��λ�ϵ����ַ�0
					words = "Hundred " + words;
					words = single[one_num] + " " + words;
				}else if(cur_digit == 0 && one_num > 0 ){       // �������λ�� 01 ~ 09
					words = single[one_num]  + " " + words;
				}else if(one_num > 0){                          // ����������� 32 �ĸ�λ
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
