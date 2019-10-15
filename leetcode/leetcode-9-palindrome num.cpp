#include<iostream>
using namespace std;

/* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 *
 * Example 1:
 *
 * Input: 121
 * Output: true
 * Example 2:
 *
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * Example 3:
 *
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * Follow up:
 *
 * Coud you solve it without converting the integer to a string?
 */



class Solution {
public:
    // 方法1，直接将x反转，判断反转后的数与原数是否相等 ,4ms 打败99%
    bool isPalindrome(int x) {
        int n = x;
		long long res = 0;                        // 用于存储翻转后的结果数，longlong防止翻转后溢出
        if(x < 0 || (x % 10 == 0 && x != 0) ){    // 负数和个位是 0 的数都不是回文数
            return false;
        }
        while(n){
        	res = res * 10 + n % 10;
			n /= 10;
		}
		return res == x;
    }

    // 方法2，反转x的一半，判断反转后的数与原数剩下一半是否相等 , 8ms 打败97%
    bool isPalindrome2(int x) {
		int res = 0;                              // 用于存储翻转后的结果数，longlong防止翻转后溢出
        if(x < 0 || (x % 10 == 0 && x != 0) ){    // 负数和个位是 0 的数都不是回文数
            return false;
        }
        while(x > res){
        	res = res * 10 + x % 10;
			x /= 10;
		}
		return res == x || res/10 == x;           // 1221 和 12321 ， 12321最终为 x = 12 ， res = 123
    }
};

int main(){
	int x;
	Solution s;
	while(cin >> x){
		cout << s.isPalindrome2(x) << endl;
	}
	return 0;
}
