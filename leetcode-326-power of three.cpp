#include<iostream>
using namespace std;

// Given an integer, write a function to determine if it is a power of three.




class Solution{
public:
    // 方法1 迭代实现
    bool isPowerOfThree(int n) {
        if( n == 1 ){
            return true;
        }else if( n%3 == 0 && n > 1){
            n /= 3;
            while(n > 1){
                if(n % 3 != 0){
                    return false;
                }
                n /= 3;
            }
            return true;
        }else{
            return false;
        }
    }
};
int main(){
    Solution s;
    cout << s.isPowerOfThree(-3) << endl;
    return 0;
}
