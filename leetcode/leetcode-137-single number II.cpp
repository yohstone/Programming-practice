#include<iostream>
#include<vector>
#include<set>
using namespace std;

//    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//
//    说明：
//
//    你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//    示例 1:
//
//    输入: [2,2,3,2]
//    输出: 3
//    示例 2:
//
//    输入: [0,1,0,1,0,1,99]
//    输出: 99
//
//    Given a non-empty array of integers, every element appears three times except for one, which appears exactly once.
//
//    Find that single one.
//
//    Note:
//
//    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



class Solution{
public:
    // 方法1，数学：
    // 3*(a+b+c) - (a+a+a++b+b+b+c) = 2c   先将 nums 放入 set 中，然后求 3 倍 set 元素的和，最后减去 nums 元素的和
    // 时间复杂度  O(2n) 空间复杂度 O(n)
    int singleNumber(vector<int>& nums){
        int len = nums.size();
        set<int> hset;
        set<int>::iterator it;
        long long sum = 0;      // 防止溢出
        if( len == 1)
            return nums[0];
        hset.insert( nums.begin(), nums.end() ); //将 vector 中的数字插入 set
        for( it = hset.begin(); it != hset.end(); it++ ){
            sum += *it;
        }
        sum = sum * 3;
        for(int i = 0; i < len; i++){
            sum = sum - nums[i];
        }
        return sum / 2;
    }

    // 方法2：位操作， 使用一个 32 大小的数组存储每一个数的位数的统计结果，若某位上的 1 到达 3 个时清 0 ；
    // 最后该数组存储的就是单个数字的二进制
    // 时间复杂度O(32n)  空间复杂度 O(32)
    int singleNumber2(vector<int>& nums){
        vector<int> bit_count(32, 0);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < 32; ++j){
                bit_count[j] += ((unsigned int)(nums[i] >> j)) % 2; // 统计每一位上 1 的个数，使用 unsigned int 是针对负数
                if(bit_count[j] == 3){      // 清 0
                    bit_count[j] = 0;
                }
            }
        }
        int res = bit_count[0];
        unsigned int tag = 1;
        for(int i = 0; i < 32; ++i){   // 将二进制转换成十进制
            if(bit_count[i] == 1){
                res |= tag << i;
            }
        }
        return res;
    }

    // 方法3 ： 位操作，不需要额外存储
    // 用 one 记录到当前处理的元素为止，二进制 1 出现 “1次”（mod 3 之后的 1）的有哪些二进制位；
    // 用 two 记录到当前计算的变量为止，二进制 1 出现 “2次”（mod 3 之后的 2）的有哪些二进制位。
    // 当 one 和 two 中的某一位同时为 1 时表示该二进制位上 1 出现了 3 次，此时需要清零。即用二进制模拟三
    // 进制运算。最终 one 记录的是最终结果。
    // 时间复杂度 O(n)  空间复杂度 O(1)
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int twice = 0;
        for (auto cur_num : nums){
            once = once ^ cur_num & ~twice;
            twice = twice ^ cur_num & ~once;
        }
        return once;
    }

};
int main(){
    Solution s;
    vector<int> nums = {2, 2, 1};
    cout << s.singleNumber1(nums) << endl;
    return 0;
}
