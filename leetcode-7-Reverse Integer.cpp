//����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
//�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ [?231,  231 ? 1]�������������裬�����ת�����������ô�ͷ��� 0��
//int ռ4�ֽ�ʱ�� ��Χ�� -2147483648 ��2147483647

#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
	//����1 
    int reverse(int x) {
        long long rev = 0;
        while(x != 0){
        	int digit = x % 10;//ȡx��ÿһλ
			rev = rev * 10 + digit;	
			if(rev > INT_MAX || rev < INT_MIN) {
				cout << rev << endl;
				return 0;
			}
			x = x/10;
		}
		return rev;
    }
    
    //����2 ��� 
    int reverse2(int x) {
        int rev = 0;
        while(x != 0){
        	int digit = x % 10;//ȡx��ÿһλ
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
