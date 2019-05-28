#include<iostream>
#include<vector>
using namespace std;

//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//Example 1:
//
//Input: [1,3,5,6], 5
//Output: 2
//Example 2:
//
//Input: [1,3,5,6], 2
//Output: 1

class Solution{
public:
    int searchInsert(vector<int>& nums, int target){
        int i=0;
        int len = nums.size();
        if(len == 0) return 0;
        for( ; i < len; i++){
            if(nums[i] >= target)
                return i;
        }
        return i;
    }
};
int main(){
    vector<int> nums ={1,3,5,6};
    Solution s;
    cout << s.searchInsert(nums, 0) << endl;
    return 0;
}
