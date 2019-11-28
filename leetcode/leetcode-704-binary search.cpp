#include<iostream>
#include<vector>
using namespace std;

//    Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
//
//    Example 1:
//    Input: nums = [-1,0,3,5,9,12], target = 9
//    Output: 4
//    Explanation: 9 exists in nums and its index is 4
//
//    Example 2:
//    Input: nums = [-1,0,3,5,9,12], target = 2
//    Output: -1
//    Explanation: 2 does not exist in nums so return -1
//
//    Note:
//    You may assume that all elements in nums are unique.
//    n will be in the range [1, 10000].
//    The value of each element in nums will be in the range [-9999, 9999].
//
//    给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
//    示例 1:
//    输入: nums = [-1,0,3,5,9,12], target = 9
//    输出: 4
//    解释: 9 出现在 nums 中并且下标为 4
//
//    示例 2:
//    输入: nums = [-1,0,3,5,9,12], target = 2
//    输出: -1
//    解释: 2 不存在 nums 中因此返回 -1
//
//    提示：
//    你可以假设 nums 中的所有元素是不重复的。
//    n 将在 [1, 10000]之间。
//    nums 的每个元素都将在 [-9999, 9999]之间。


class Solution {
public:
    // 二分查找法
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        int left = 0;
        int right = len - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] == target){
                return mid;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    
    return 0;
}
