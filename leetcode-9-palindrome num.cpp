#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
		long long n=0; //翻转后的数，longlong防止翻转后溢出 
        if(x < 0 || (x%10 == 0 && x != 0) ) return false; 
        while(temp){
        	n = n*10 + temp%10;
			temp /= 10; 
		}
		if(n == x) return true;
		else return false;
    }
};

int main(){
	int x;
	Solution s;
	while(cin >> x){
		cout << s.isPalindrome(x) << endl;
	} 
	return 0;
}
