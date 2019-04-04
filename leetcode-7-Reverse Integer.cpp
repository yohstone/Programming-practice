//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
//假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [?231,  231 ? 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
//int 占4字节时， 范围是 -2147483648 到2147483647

#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
	//方法1 
    int reverse(int x) {
        long long rev = 0;
        while(x != 0){
        	int digit = x % 10;//取x的每一位
			rev = rev * 10 + digit;	
			if(rev > INT_MAX || rev < INT_MIN) {
				cout << rev << endl;
				return 0;
			}
			x = x/10;
		}
		return rev;
    }
    
    //方法2 题解 
    int reverse2(int x) {
        int rev = 0;
        while(x != 0){
        	int digit = x % 10;//取x的每一位
			if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit > 7)) return 0;
			if(rev < INT_MIN/10 || (rev == INT_MIN/10 && digit < -8)) return 0;
			rev = rev * 10 + digit;	
			x = x/10;
		}
		return rev;
    }
    
};
int main(){
	Solution s;
	cout << s.reverse2(-2143847412);
	return 0;
}
