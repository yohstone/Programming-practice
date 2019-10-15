#include<iostream>
#include<vector>
using namespace std;

/* For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].
 *
 * Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.
 *
 *  
 *
 * Example 1:
 *
 * Input: A = [1,2,0,0], K = 34
 * Output: [1,2,3,4]
 * Explanation: 1200 + 34 = 1234
 */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K){
        int carry = 0;  // 进位
        int KDigit;     // K的各个位数
        int i = A.size()-1;
        while(K != 0 || carry != 0 ){
            KDigit = K % 10;
            K /= 10;
            if( i < 0){ // K长度大于A的情况
                KDigit += carry;
                if( KDigit >= 10){
                    carry = KDigit/10;
                    KDigit = KDigit%10;
                }else{
                    carry = 0;
                }
                A.insert( A.begin(), KDigit);
            }else{
                A[i] = A[i] + carry + KDigit;
                carry = 0;
                if( A[i] >= 10 ){
                    carry = A[i] / 10;
                    A[i] = A[i] % 10;
                }
                i--;
            }
        }
        return A;
    }
};
int main(){
    vector<int> digits = {7};
    Solution s;
    s.addToArrayForm( digits, 993 );
    for(int i=0; i<digits.size(); i++){
        cout << digits[i] << " " ;
    }
}
