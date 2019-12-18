#include<iostream>
#include<vector>
using namespace std;

//    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//    ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
//
//    编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
//
//    示例 1:
//
//    输入: nums = [2,5,6,0,0,1,2], target = 0
//    输出: true
//    示例 2:
//
//    输入: nums = [2,5,6,0,0,1,2], target = 3
//    输出: false
//    进阶:
//
//    这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
//    这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
//        会，会导致有时无法判断某半部分是否有序，因为可能 nums[left] == nums[mid] 或 nums[right] == nums[mid]，
//        此时只需要跳过就行，即 left++ 或 right--
//
//    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//    (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
//    You are given a target value to search. If found in the array return true, otherwise return false.



class Solution {
public:

    // 方法1：二分查找法变形
    // 因为有翻转，所以用 mid 将 nums 分为两半，则必有一半有序，一半部分有序
    // 当 nums[left] == nums[mid]，分不清到底是前面有序还是后面有序，此时 left++ 即可。相当于去掉一个重复的干扰项。
    // 然后判断 target 在哪一半里,继续在那一半进行二分查找
    // 4ms
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return true;
            }

            if(nums[left] < nums[mid]){         // 前半部分有序
                if(nums[left] <= target && target < nums[mid]){ // 且 target 在前半部分的范围内
                    right = mid - 1;                            // 继续在前半部分进行二分查找
                }else{                                          // 不在前半部分，则在后半部分查找
                    left = mid +  1;
                }
            }else if(nums[left] == nums[mid]){  //  跳过重复的数
                ++left;
            }else{                              // 后半部分有序
                if(nums[mid] < target && target <= nums[right] ){ // 且 target 在后半部分的范围内
                    left = mid + 1;                               // 继续在后半部分进行二分查找
                }else{                                            // 不在后半部分，则在前半部分查找
                    right = mid - 1;
                }
            }

        }
        return false;
    }


};

int main(){
    return 0;
}
