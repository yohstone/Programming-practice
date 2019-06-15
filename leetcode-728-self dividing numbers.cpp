#include<iostream>
#include<vector>
using namespace std;

/* A self-dividing number is a number that is divisible by every digit it contains.
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 *
 * Also, a self-dividing number is not allowed to contain the digit zero.
 *
 * Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
 *
 * Example 1:
 * Input:
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 */



class Solution{
public:
    vector<int> selfDividingNumbers(int left, int right){
        vector<int> res; //结果数组
        for(int i=left; i<=right; i++){
            int num = i;
            int flag = 0; // 是否是自除数标志变量，0不是，1是
            while(num){
                int digit = num % 10;
                if( digit != 0 && i%digit == 0 ){
                    flag = 1;
                    num /= 10;
                }else{
                    flag = 0;
                    break;
                }
            }
            if(flag){
                res.push_back(i);
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums;
    nums = s.selfDividingNumbers(1, 22);
    for(int j=0; j<nums.size(); j++){
        cout << nums[j] << endl;
    }
    return 0;
}

