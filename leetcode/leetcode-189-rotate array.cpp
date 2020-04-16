#include<iostream>
using namespace std;

    // 189. 旋转数组

    // Given an array, rotate the array to the right by k steps, where k is non-negative.
    // 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

    // 示例 1:

    // 输入: [1,2,3,4,5,6,7] 和 k = 3
    // 输出: [5,6,7,1,2,3,4]
    // 解释:
    // 向右旋转 1 步: [7,1,2,3,4,5,6]
    // 向右旋转 2 步: [6,7,1,2,3,4,5]
    // 向右旋转 3 步: [5,6,7,1,2,3,4]
    // 示例 2:

    // 输入: [-1,-100,3,99] 和 k = 2
    // 输出: [3,99,-1,-100]
    // 解释: 
    // 向右旋转 1 步: [99,-1,-100,3]
    // 向右旋转 2 步: [3,99,-1,-100]
    // 说明:

    // 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
    // 要求使用空间复杂度为 O(1) 的 原地 算法。




class Solution {
public:
    // 方法1：使用额外的数组空间进行旋转
    // 时间复杂度：O(n) 空间复杂度：O(n)
    void rotate(vector<int>& nums, int k) {
        
        int len = nums.size();
        vector<int> temp(len, 0);
        // 旋转
        for(int i = 0; i < len; ++i){
            int new_index = (i + k) % len;
            temp[new_index] = nums[i];
        }
        // 复制回原数组
        for(int i = 0; i < len; ++i){
            nums[i] = temp[i];
        }

    }

    // 方法2：暴力法，直接对原数组进行 k 次旋转，每次旋转 1 个单位
    // 时间复杂度：O(n * k) 空间复杂度：O(1)
    void rotate2(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        for(int i = 0; i < k; ++i){
            int temp = nums[len - 1];
            for(int j = len - 1; j > 0; --j){
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
    }

    // 方法3：直接将数字放入它最终的位置，并使用一个变量来暂存该位置之前的数字
    // 时间复杂度：O(n) 空间复杂度：O(1)
    void rotate3(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int count = 0;          // 存放次数，因为共有 n 个数，所有当次数为 n 时，算法结束
        for(int start_index = 0; count < len; ++start_index){
            int cur_index = start_index;
            int cur_num = nums[start_index];
            do{
                int next_index = (cur_index + k) % len; // 计算当前数字的最终位置
                int temp_num = nums[next_index];        // 存下最终位置中的数字
                nums[next_index] = cur_num;             // 将当前数字放入最终位置
                cur_num = temp_num;
                cur_index = next_index;
                ++count;
            }while(cur_index != start_index);           // 防止出现两个位置循环操作
        }
        
    }

};



int main(){
    return 0;
}
