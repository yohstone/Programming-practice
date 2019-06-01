#include<iostream>
using namespace std;

//Given an integer, write a function to determine if it is a power of two.
//
//Example 1:
//
//Input: 1
//Output: true
//Explanation: 20 = 1
//Example 2:
//
//Input: 16
//Output: true
//Explanation: 24 = 16

class Solution{
public:
    bool isPowerOfTwo(int n){
        if( n > 0 && ( n & (n-1)) == 0  )
            return true;
        else
            return false;
    }
};

int main(){
    Solution s;
    cout << s.isPowerOfTwo(16) <<endl;
    return 0;
}
