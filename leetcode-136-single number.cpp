#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
//Example 1:
//
//Input: [2,2,1]
//Output: 1
//Example 2:
//
//Input: [4,1,2,1,2]
//Output: 4


class Solution{
public:
    // 方法1，数学：
    // 2*(a+b+c) - (a+a+b+b+c) = c   先将nums放入set中，然后求2倍set元素的和，最后减去nums元素的和
    // 得用到额外空间了   时间复杂度  O(2n) 60ms
    int singleNumber1(vector<int>& nums){
        int len = nums.size();
        set<int> hset;
        set<int>::iterator it;
        int sum = 0;
        if( len == 1)
            return nums[0];
        hset.insert( nums.begin(), nums.end() ); //将vector中的数字插入set
        for( it = hset.begin(); it != hset.end(); it++ ){
            sum += *it;
        }
        sum = sum*2;
        for(int i = 0; i < len; i++){
            sum = sum - nums[i];
        }
        return sum;
    }
    // 方法2：位操作， 效率最高 时间复杂度O(n)  16ms
    int singleNumber2(vector<int>& nums){
        int c = 0;
        for(int i=0; i<nums.size(); i++){
            c ^= nums[i];
        }
        return c;

    }
    // 方法3：使用set，若不存在set里则插入，若存在set中则删除，最后剩余一个值
    // 需要额外空间      36ms O(n*log(n))
    int singleNumber3(vector<int>& nums){
        set<int> hset;
        for(int i=0; i<nums.size(); i++){
            if(hset.find(nums[i]) != hset.end())
                hset.erase(nums[i]);
            else
                hset.insert(nums[i]);
        }
        return *hset.begin();

    }
};
int main(){
    Solution s;
    vector<int> nums = {2, 2, 1};
    cout << s.singleNumber1(nums) << endl;
    return 0;
}
