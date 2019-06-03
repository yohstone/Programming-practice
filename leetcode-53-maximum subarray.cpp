#include<iostream>
#include<vector>
using namespace std;

//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2,1,-3,4,-1,2,1,-5,4],
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int sum = 0;
        int res = nums[0];
        for(int i=0; i<nums.size(); i++){
            sum =  sum>0 ? sum+nums[i] : nums[i]; //连续子序列的和，前面相加小于0，则可直接从nums[i]重新开始
            if(sum > res){
                res = sum;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    return 0;

}
