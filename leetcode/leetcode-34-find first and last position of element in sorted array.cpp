#include<iostream>
#include<vector>
using namespace std;

//    给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//    你的算法时间复杂度必须是 O(log n) 级别。
//
//    如果数组中不存在目标值，返回 [-1, -1]。
//
//    示例 1:
//
//    输入: nums = [5,7,7,8,8,10], target = 8
//    输出: [3,4]
//    示例 2:
//
//    输入: nums = [5,7,7,8,8,10], target = 6
//    输出: [-1,-1]
//
//    Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//    Your algorithm's runtime complexity must be in the order of O(log n).
//
//    If the target is not found in the array, return [-1, -1].



class Solution {
public:
    // 方法1：线性遍历，先遍历到第一个位置，然后再倒过来遍历到最后一个位置。
    // 时间复杂度 O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int len = nums.size();
        if(len == 0){
            return res;
        }
        for(int i = 0; i < len; ++i){       // 查找开始位置
            if(nums[i] == target){
                res[0] = i;
                break;
            }
        }
        if(res[0] == -1){                   // 数组中没有目标值
            return res;
        }
        for(int i = len - 1; i >= 0; --i){  // 查找结束位置
            if(nums[i] == target){
                res[1] = i;
                break;
            }
        }

        return res;
    }

    // 方法2：使用两次二分查找法，先找到开始位置，再找到结束位置
    // 时间复杂度 O(log2n)
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> res(2, -1);
        int len = nums.size();
        if(len == 0){
            return res;
        }
        // 先找开始位置,左闭右开
        int left = 0;
        int right = len;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                right = mid;
            }else if(nums[mid] > target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        if(left == len){
            return res;
        }else if(nums[left] == target){
            res[0] = left;
        }

        // 再找结束位置，左开右闭
        left = -1;
        right = len - 1;
        while(left < right){
            int mid = (left + right + 1) / 2; // 相当于向上取整，因为右边是闭的
            if(nums[mid] == target){
                left = mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid;
            }
        }
        if(right == -1){
            return res;
        }else if(nums[right] == target){
            res[1] = right;
        }
        return res;
    }
};
int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 0) << endl;
    return 0;
}
