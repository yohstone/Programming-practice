#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

/* Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */


class Solution{
public:

    // 会进入循环的不快乐数
    vector<int> unhappyNums = {4,16,37,58,89,145,42,20};

    // 方法1： 递归法，出现不快乐循环数直接return false
    bool isHappy(int n){
        int digit;
        int sum  = 0;
        if( n == 1) return true;
        if( n == 0 || find(unhappyNums.begin(), unhappyNums.end(), n) != unhappyNums.end() ){
            return false;
        }
        while(n){
            digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return isHappy(sum);
    }


    // 方法2： 记录下生成的和，若相同则进入循环，return false;
    bool isHappy2(int n){
        int digit;
        int sum  = n;
        set<int> resSums;

        while( sum != 1){
            sum = 0;
            while(n){
                digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            if( resSums.count(sum) != 0){
                return false;
            }else{
                resSums.insert(sum);
            }
            n = sum;
        }
        return true;
    }
};
int main(){
    Solution s;
    int n;
    while( cin >> n ){
        cout << s.isHappy2(n) << endl;
    }
    return 0;
}
