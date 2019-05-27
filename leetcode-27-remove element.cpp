//
//  leetcode-27-remove element.cpp
//  leetcode-code
//
//  Created by Steve Stone on 2019/5/26.
//  Copyright © 2019年 Steve Stone. All rights reserved.
//
//
//Given an array nums and a value val, remove all instances of that value in-place and return the new length.

//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
        int removeElement(vector<int>& nums, int val) {
        int resIndex = 0;//结果数组的下标索引
        int nowIndex;
        if(nums.size() == 0) return 0;
        for(nowIndex = 0; nowIndex < nums.size(); nowIndex++){
            if(nums[nowIndex] != val ){
                nums[resIndex] = nums[nowIndex];
                resIndex++;
            }
        }
        return resIndex;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,3,4};
    int len;
    //len = s.removeDuplicates(nums);
    len = s.removeElement(nums, 4);
    for(int i=0; i<len; i++)
        cout << nums[i] << " ";
    cout << endl;
    return 0;
}
