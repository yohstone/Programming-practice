#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 * The solution set must not contain duplicate triplets.
 *
 * Example:
 *
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */


class Solution{
public:
    // 双指针法，先给数组排序，然后从头开始，依次以每个负数作为固定数字，使用头尾双指针遍历接下来的数组，寻找与该负数之和为 0 的另外两位数字
    vector<vector<int> > threeSum(vector<int>& nums){
        int len = nums.size();
        sort(nums.begin(), nums.end());
        if(len < 3 || nums[0] > 0 || nums[len-1] < 0){         // 若数组中的元素小于 3 或最小的数大于 0 或最大的数小于0，结果肯定为空
            return {};
        }

        vector<vector<int> > res;
        for(int i = 0; i < len; i++){
            if(nums[i] > 0){                                   // 因为数组已排序，所以当 nums[i] > 0 时就已经没有负数了，可以结束循环了
                break;
            }

            if(i > 0 && nums[i] == nums[i-1]){                 // 跳过与之前相等的负数，防止出现重复的结果集合
                continue;
            }

            int left  = i + 1;                                 // 左指针
            int right = len - 1;                               // 右指针
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){

                    if(left == i + 1 || right == len - 1){     // 先将最先满足的存下，再判断之后是否有重复，防止漏数据，如[0,0,0]
                        res.push_back(vector<int> {nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                    }else if(nums[left] == nums[left - 1]){    // 跳过重复的元素，防止出现重复的结果集合
                        left++;
                    }else if(nums[right] == nums[right + 1]){  // 跳过重复的元素，防止出现重复的结果集合
                        right--;
                    }else{
                        res.push_back(vector<int> {nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                }else if(nums[left] + nums[right] < -nums[i]){  // 左右指针指向的数之和太小了，此时应增大某个数，所以left++
                    left++;
                }else{                                          // 左右指针指向的数之和太大了，此时应减小某个数，所以right--
                    right--;
                }
            }// end while
        }// end for
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    cout << s.threeSum(nums).size() << endl;
    return 0;
}
