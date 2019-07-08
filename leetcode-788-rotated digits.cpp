#include<iostream>
using namespace std;

/*
 * X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.
 *
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.
 *
 * Now given a positive number N, how many numbers X from 1 to N are good?
 *
 * Example:
 * Input: 10
 * Output: 4
 * Explanation:
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
 */


class Solution{
public:
    // 好数，必不含3,4,7；至少包含2,5,6,9中的一个
    int rotatedDigits(int N){
        int count = 0;
        for(int i = 1; i <= N; i++){ // 0和1必然不是好数，跳过
            int n = i;
            bool isGood = false; // 是否是好数标志位，至少包含2、5、6、9中的一个是为true
            while(n){
                int digit = n % 10;
                if(digit == 3 || digit == 4 || digit == 7){
                    break;
                }
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                    isGood = true;
                }
                n /= 10;
            }
            if(n == 0 && isGood){
                count++;
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    cout << s.rotatedDigits(2) << endl;
}
