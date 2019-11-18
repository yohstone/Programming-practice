#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

//    给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
//
//    例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
//
//    与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).



#define INFINITY 65535       // 定义无穷大
class Solution {
public:
    // 方法1：三指针法，先固定一个指针，然后使用双指针遍历接下来的数字，当双指针相遇时改变固定的那个指针
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());                         // 先对 nums 进行排序
        int min_interval = INFINITY;                            // 3数之和与target的当前最小距离，默认值无穷大
        int res;
        for(int i = 0; i < len - 2; i++){                       // 从头开始遍历 nums 固定 nums[i]， 求其他两个数与 nums[i]相加最接近target
            if(i > 0 && nums[i] == nums[i-1]){
                continue;                                       // 跳过重复的数字，提高效率
            }
            int left = i + 1, right = len - 1;                  // 左右指针，分别指向nums[i] 之后数据的首和尾
            int curr_sum = 0;                                   // 当前3个数的和
            int curr_interval;                                  // 当前和与target的差值
            while(left < right){
                curr_sum = nums[i] + nums[left] + nums[right];  // 计算当前3个数的和
                curr_interval = curr_sum - target;              // 3个数之和与 target 的差
                if(abs(curr_interval) < min_interval){          // 如果差小于当前最小的差值
                    res = curr_sum;
                    min_interval = abs(target - curr_sum);

                }
                if(curr_interval < 0){                          // 若差值小于0 说明需要增大3数之和，所以left++
                    left++;
                }else{                                          // 若差值大于0 说明需要减小3数之和，所以right--
                    right--;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0,2,1,-3};
    int target = 1;
    Solution s;
    cout << s.threeSumClosest(nums, target) << endl;
    return 0;
}
