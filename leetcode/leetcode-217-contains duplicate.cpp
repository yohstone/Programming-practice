#include<iostream>
#include<vector>
#include<set>
#include
using namespace std;

//    给定一个整数数组，判断是否存在重复元素。
//
//    如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
//
//    示例 1:
//
//    输入: [1,2,3,1]
//    输出: true
//    示例 2:
//
//    输入: [1,2,3,4]
//    输出: false
//    示例 3:
//
//    输入: [1,1,1,3,3,4,3,2,4,2]
//    输出: true
//
//    Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

class Solution {
public:
    // 方法1 ： 使用 set 的不重复性质，将 nums 中的元素复制到 set 中，若容器中元素个数不变，则不含重复元素
    bool containsDuplicate(vector<int>& nums) {
        set<int> numsSet( nums.begin(), nums.end() );
        return numsSet.size() != nums.size();
    }

    // 方法2：先排序，然后判断相邻元素是否相等
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 1; ++i){
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }

};
int main(){
    Solution s;
    vector<int> nums = {7,3,2,1,2};
    cout << s.containsDuplicate(nums) <<endl;
    return 0;
}
