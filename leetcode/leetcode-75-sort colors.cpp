#include<iostream>
#include<vector>
using namespace std;

    // 75. 颜色分类

    // 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

    // 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

    // 注意:
    // 不能使用代码库中的排序函数来解决这道题。

    // 示例:

    // 输入: [2,0,2,1,1,0]
    // 输出: [0,0,1,1,2,2]
    // 进阶：

    // 一个直观的解决方案是使用计数排序的两趟扫描算法。
    // 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
    // 你能想出一个仅使用常数空间的一趟扫描算法吗？



    // Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

    // Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    // Note: You are not suppose to use the library's sort function for this problem.

    // Example:

    // Input: [2,0,2,1,1,0]
    // Output: [0,0,1,1,2,2]
    // Follow up:

    // A rather straight forward solution is a two-pass algorithm using counting sort.
    // First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
    // Could you come up with a one-pass algorithm using only constant space?



class Solution {
public:
    // 方法1： 使用一个长度为 3 的数组（或者3个变量）统计各个颜色数字的个数，然后根据统计结果修改原数组
    // 时间复杂度 O(n)   空间复杂度 O(1)
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        vector<int> nums_count(3, 0);  // 用于统计 0， 1， 2的个数
        for(int i = 0; i < len; ++i){
            ++nums_count[nums[i]];
        }
        for(int i = 0; i < len; ++i){
            if(nums_count[0] > 0){
                nums[i] = 0;
                --nums_count[0];
            }else if(nums_count[1] > 0){
                nums[i] = 1;
                --nums_count[1];
            }else if(nums_count[2] > 0){
                nums[i] = 2;
                --nums_count[2];
            }
        }
    }

    // 方法2： 使用首尾指针和 i 指针，共 3 个指针对数组进行遍历，以实现将 0 放到起始位置，
    //        将 2 放到数组末尾。
    // 时间复杂度 O(n)   空间复杂度 O(1)
    void sortColors2(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        for(int i = 0; i <= right; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[left++]);
            }
            if(nums[i] == 2){
                swap(nums[i--], nums[right--]); // i-- 是因为被交换的 nums[right] 还没有被判断
            }
        }
        
    }
};

int main() {
    Solution s;

    return 0;
}
