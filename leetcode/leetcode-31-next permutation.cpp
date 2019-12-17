#include<iostream>
#include<algorithm>
using namespace std;
//
//    实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//
//    如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//
//    必须原地修改，只允许使用额外常数空间。
//
//    以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//    1,2,3 → 1,3,2
//    3,2,1 → 1,2,3
//    1,1,5 → 1,5,1
//
//    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//    If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//    The replacement must be in-place and use only constant extra memory.
//
//    Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.



class Solution {
public:
//  方法1：
//    1. 先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
//    2. 再找出另一个最大索引 l 满足 nums[l] > nums[k]；
//    3. 交换 nums[l] 和 nums[k]；
//    4. 最后翻转 nums[k+1:]。
    void nextPermutation(vector<int>& nums) {
        int first_index = -1;       // k
        int second_index = -1;      // l
        int len = nums.size();
        for(int i = len - 2; i >= 0; --i){               // 1. 寻找 nums[k] < nums[k + 1] 中最大的 k
            if(nums[i] < nums[i + 1]){
                first_index = i;
                break;
            }
        }
        if(first_index == -1){                           // 不存在 nums[k] < nums[k + 1]
            reverse(nums.begin(), nums.end());
            return ;
        }
        for(int i = len - 1; i >= 0; --i){                // 2. 寻找 nums[l] > nums[k] 中最大的 l
            if(nums[i] > nums[first_index]){
                second_index = i;
                break;
            }
        }
        swap(nums[first_index], nums[second_index]);      // 3. 交换 nums[l] 和 nums[k]
        reverse(nums.begin() + first_index + 1, nums.end());   // 4. 翻转 nums[k + 1: ]
    }

    // 方法2：使用 STL 库 <algorithm>
    void nextPermutation2(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

int main(){
    return 0;
}
