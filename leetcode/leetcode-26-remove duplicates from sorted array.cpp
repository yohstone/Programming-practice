//
//  leetcode-26-remove duplicates from sorted array.cpp
//  
//
//  Created by Steve Stone on 2019/5/25.
//
//
//Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

//Example 2:

//Given nums = [0,0,1,1,1,2,2,3,3,4],

//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

//It doesn't matter what values are set beyond the returned length.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int resIndex = 0;//结果数组的下标索引
        int nowIndex;
        for(nowIndex = 0; nowIndex < nums.size(); nowIndex++){
            if(nums[nowIndex] != nums[resIndex] ){
                resIndex++;
                nums[resIndex] = nums[nowIndex];
                
            }
        }
        return nums.size();
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,3,4};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}
