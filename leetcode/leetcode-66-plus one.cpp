#include<iostream>
#include<vector>
using namespace std;

/* Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 */


class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int carry = 1;  // 进位, 初始为1，因为最后一位需要加1
        for(int i=digits.size()-1; i>=0; i--){
            digits[i] = digits[i] + carry;
            carry = 0;
            if(digits[i] >= 10){
                carry = 1;
                digits[i] = digits[i] % 10;
                if( i == 0 ){
                    digits.insert( digits.begin(), carry);
                }
            }else{
                break;
            }
        }
        return digits;

    }
};
int main(){
    vector<int> digits = {1,2,3,4};
    Solution s;
    s.plusOne( digits );
    for(int i=0; i<digits.size(); i++){
        cout << digits[i] << " " ;
    }
}
