#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Example:
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */


class Solution {
public:
    // 先计算每个数左边的乘积，存入结果容器里，再计算每个数右边的乘积，与结果容器里的左边乘积相乘得出结果
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        int left_product = 1;
        for(int i = 0; i < len; i++){
            res[i] = left_product;              // 存储当前数的左边的乘积结果
            left_product *= nums[i];
        }
        int right_product = 1;
        for(int i = len - 1; i >= 0; i--){
            res[i] = res[i] * right_product;    // 左边乘积已存储在容器里了，所以直接乘以右边乘积作为结果
            right_product *= nums[i];
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    vector<int> res;
    res = s.productExceptSelf(nums);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}
