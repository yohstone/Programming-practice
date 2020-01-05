#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//    给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
//
//    示例 :
//
//    输入: [1,2,1,3,2,5]
//    输出: [3,5]
//    注意：
//
//    结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
//    你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
//
//    Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//    Find the two elements that appear only once.
//
//    Example:
//
//    Input:  [1,2,1,3,2,5]
//    Output: [3,5]
//    Note:
//
//    The order of the result is not important. So in the above example, [5, 3] is also correct.
//    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?




class Solution {
public:
    // 方法1：哈希表，用哈希表存每个数，当出现第二次时将数从哈希表中删除，最后表中只存在结果两个数
    // 时间复杂度 O(n) 空间复杂度 O(n)
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> nums_count;
        for(int num : nums){
            // 在 C++ 中，通过 unordered_set 的 insert 方法添加元素时
            // 将返回一个 pair<iterator, bool> 对象
            // 其 second 为一布尔类型的值，标识是否添加成功
            if(!nums_count.insert(num).second){
                nums_count.erase(num);                          // 重复便移除
            }
              // 或使用如下方法
//            if(nums_count.find(num) != nums_count.end()){       // 若存在表中则删除
//                nums_count.erase(num);
//            }else{                                              // 若不存在则添加
//                nums_count.insert(num);
//            }
        }
        vector<int> res(nums_count.begin(), nums_count.end());  // 转换结果
        return res;
    }

    // 方法2：位运算法，先异或所有的数，得到只出现一次的两个数的异或值 x
    // 然后使用 x & -x 得到只含有 x 最后一位 1 的数 lowbit，
    // 然后使用 nums[i] & lowbit == lowbit 将 nums 分为两组，一组含 lowbit 中的 1 ，一组不含
    // 最后两组分别异或，得到结果
    // 时间复杂度 O(2n)  空间复杂度 O(1)
    vector<int> singleNumber2(vector<int>& nums) {
        int len = nums.size();
        int x = 0;
        for(int i = 0; i < len; ++i){       // 全部异或得到 x
            x ^= nums[i];
        }
        int lowbit = x & -x;                // 得到只含有 x 的最后一位 1 的数
        int a = 0, b = 0;                   // 用于存储两个结果
        for(int i = 0; i < len; ++i){
            if((nums[i] & lowbit) == lowbit){ // 异或含有 lowbit 的数
                a ^= nums[i];
            }else{                          // 异或不含有 lowbit 的数
                b ^= nums[i];
            }
        }
        return vector<int> {a, b};
    }

};
int main(){
    Solution s;
    vector<int> nums = {2, 2, 1};
    cout << s.singleNumber(nums) << endl;
    return 0;
}
