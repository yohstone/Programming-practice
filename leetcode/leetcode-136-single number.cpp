#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

//    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//    说明：
//
//    你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//    示例 1:
//
//    输入: [2,2,1]
//    输出: 1
//    示例 2:
//
//    输入: [4,1,2,1,2]
//    输出: 4
//
//    Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
//    Note:
//
//    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


class Solution {
public:
    // 方法1，数学：
    // 2*(a+b+c) - (a+a+b+b+c) = c   利用 set 的唯一性，先将 nums 放入 set 中，
    // 然后求 2 倍 set 中元素的和，最后减去 nums 元素的和
    // 时间复杂度  O(2n) 60ms 空间复杂度 O(n)
    int singleNumber1(vector<int>& nums) {
        int len = nums.size();
        set<int> hset;
        set<int>::iterator it;
        int sum = 0;
        if( len == 1)
            return nums[0];
        hset.insert( nums.begin(), nums.end() ); // 将 vector 中的数字插入 set
        for( it = hset.begin(); it != hset.end(); it++ ) {
            sum += *it;
        }
        sum = sum * 2;
        for(int i = 0; i < len; i++) {
            sum = sum - nums[i];
        }
        return sum;
    }

    // 方法2：位操作， 效率最高 时间复杂度O(n)  16ms 空间复杂度 O(1)
    int singleNumber2(vector<int>& nums) {
        int c = 0;
        for(int i = 0; i < nums.size(); i++) {
            c ^= nums[i];
        }
        return c;

    }
    // 方法3：使用哈希表 unordered_set，若不存在 set 里则插入，若存在 set 中则删除，最后剩余一个值
    // 20ms 时间复杂度 O(n) 空间复杂度 O(n)
    int singleNumber3(vector<int>& nums) {
        unordered_set<int> hset;
        for(int i = 0; i < nums.size(); i++) {
            if(hset.find(nums[i]) != hset.end())
                hset.erase(nums[i]);
            else
                hset.insert(nums[i]);
        }
        return *hset.begin();

    }
};
int main() {
    Solution s;
    vector<int> nums = {2, 2, 1};
    cout << s.singleNumber1(nums) << endl;
    return 0;
}
