#include<iostream>
#include<vector>
using namespace std;

//    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//    你可以假设数组中无重复元素。
//
//    Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//    You may assume no duplicates in the array.
//    Example 1:
//
//    Input: [1,3,5,6], 5
//    Output: 2
//    Example 2:
//
//    Input: [1,3,5,6], 2
//    Output: 1

class Solution {
public:
    // 方法1：暴力遍历法
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int len = nums.size();
        if(len == 0)
            return 0;
        for( ; i < len; i++) {
            if(nums[i] >= target)
                return i;
        }
        return i;
    }

    // 方法2：二分查找法
    int searchInsert2(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int left = 0;
        int right = len - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return left;
    }
};
int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 0) << endl;
    return 0;
}
