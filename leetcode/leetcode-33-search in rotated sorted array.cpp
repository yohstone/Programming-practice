#include<iostream>
#include<vector>
using namespace std;

//    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//
//    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//
//    你可以假设数组中不存在重复的元素。
//
//    你的算法时间复杂度必须是 O(log n) 级别。
//
//    示例 1:
//
//    输入: nums = [4,5,6,7,0,1,2], target = 0
//    输出: 4
//    示例 2:
//
//    输入: nums = [4,5,6,7,0,1,2], target = 3
//    输出: -1
//
//
//    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
//    You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//    You may assume no duplicate exists in the array.
//
//    Your algorithm's runtime complexity must be in the order of O(log n).


class Solution {
public:

    // 方法1：常规二分查找法
    // 因为有翻转，所以用 mid 将 nums 分为两半，则必有一半有序，一半部分有序
    // 然后判断 target 在哪一半里,继续在那一半进行二分查找
    // 4ms
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[left] <= nums[mid]){  // 前半部分有序
                if(nums[left] <= target && target < nums[mid]){ // 且 target 在前半部分的范围内
                    right = mid - 1;                            // 继续在前半部分进行二分查找
                }else{                                          // 不在前半部分，则在后半部分查找
                    left = mid +  1;
                }
            }else{                        // 后半部分有序
                if(nums[mid] < target && target <= nums[right] ){ // 且 target 在后半部分的范围内
                    left = mid + 1;                               // 继续在后半部分进行二分查找
                }else{                                            // 不在后半部分，则在前半部分查找
                    right = mid - 1;
                }
            }

        }
        return -1;
    }

    // 方法2： 巧妙的二分查找法，总结各种情况导出只需要判断三个条件就行
    //  最快 4ms 91%
    int search2(vector<int>& nums, int target) {
        int left  = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid])){
                 left = mid + 1;
            }
            else{
                 right = mid;
            }
        }
        return left == right && nums[left] == target ? left : -1;
    }

//    nums[0] <= nums[mid]（0 - mid不包含旋转）且nums[0] <= target <= nums[mid] 时 high 向前规约；
//
//    nums[mid] < nums[0]（0 - mid包含旋转），target <= nums[mid] < nums[0] 时向前规约（target 在旋转位置到 mid 之间）
//
//    nums[mid] < nums[0]，nums[mid] < nums[0] <= target 时向前规约（target 在 0 到旋转位置之间）
//
//    其他情况向后规约
//
//    也就是说nums[mid] < nums[0]，nums[0] > target，target > nums[mid] 三项均为真或者只有一项为真时向后规约。
//
//    原文的分析是：
//
//    注意到原数组为有限制的有序数组（除了在某个点会突然下降外均为升序数组）
//
//    if nums[0] <= nums[I] 那么 nums[0] 到 nums[i] 为有序数组,那么当 nums[0] <= target <= nums[i] 时我们应该在 0-i0−i 范围内查找；
//
//    if nums[i] < nums[0] 那么在 0-i0−i 区间的某个点处发生了下降（旋转），那么 I+1I+1 到最后一个数字的区间为有序数组，
//    并且所有的数字都是小于 nums[0] 且大于 nums[i]，当target不属于 nums[0] 到 nums[i] 时（target <= nums[i] < nums[0] or nums[i] < nums[0] <= target），
//    我们应该在 0-i0−i 区间内查找。
//    上述三种情况可以总结如下：
//
//        nums[0] <= target <= nums[i]
//                   target <= nums[i] < nums[0]
//                             nums[i] < nums[0] <= target
//    所以我们进行三项判断：
//
//    (nums[0] <= target)， (target <= nums[i]) ，(nums[i] < nums[0])，现在我们想知道这三项中有哪两项为真（明显这三项不可能均为真或均为假（因为这三项可能已经包含了所有情况））
//
//    所以我们现在只需要区别出这三项中有两项为真还是只有一项为真。
//
//    使用 “异或” 操作可以轻松的得到上述结果（两项为真时异或结果为假，一项为真时异或结果为真，可以画真值表进行验证）
//
//    之后我们通过二分查找不断做小 target 可能位于的区间直到 low==high，此时如果 nums[low]==target 则找到了，如果不等则说明该数组里没有此项。

};

int main(){
    return 0;
}
