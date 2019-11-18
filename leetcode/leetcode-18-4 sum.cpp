#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//    给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//    注意：
//
//    答案中不可以包含重复的四元组。
//
//    示例：
//
//    给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//    满足要求的四元组集合为：
//    [
//      [-1,  0, 0, 1],
//      [-2, -1, 1, 2],
//      [-2,  0, 0, 2]
//    ]
//
//    Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//    Note:
//
//    The solution set must not contain duplicate quadruplets.
//
//    Example:
//
//    Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
//    A solution set is:
//    [
//      [-1,  0, 0, 1],
//      [-2, -1, 1, 2],
//      [-2,  0, 0, 2]
//    ]

class Solution{
public:


    // 四指针法，先给数组排序，然后固定第1,第2个指针，使用双指针遍历数组，当双指针相遇时，修改第2个指针，当第2个指针遍历完数组时，修改第1个指针
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 4)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int p1 = 0; p1 <= len - 4; ++p1){
            if(p1 > 0 && nums[p1] == nums[p1 - 1])          // 确保 nums[p1] 改变了，防止重复
                continue;

            if (nums[p1] + nums[p1 + 1] + nums[p1 + 2] + nums[p1 + 3] > target)     // 最小的数字组合都比 target 大，找不到满足条件的组合，结束循环
                break;
            if (nums[p1] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)  // nums[p1]与最大的数字组合都比 target 小，找不到满足条件的组合，跳过该nums[p1]
                continue;

            for(int p2 = p1 + 1; p2 <= len - 3; ++p2){
                if(p2 > p1 + 1 && nums[p2] == nums[p2 - 1]) // 确保 nums[p2] 改变了，防止重复
                    continue;

                if (nums[p2] + nums[p2 + 1] + nums[p2 + 2] > target - nums[p1])     // 最小的数字组合都比 target - nums[p1] 大，找不到满足条件的组合，结束循环
                    break;
                if (nums[p2] + nums[len - 2] + nums[len - 1] < target - nums[p1])   // nums[p2]与最大的数字组合都比 target - nums[p1] 小，找不到满足条件的组合，跳过该nums[p2]
                    continue;

                int left = p2 + 1;
                int right = len - 1;
                while(left < right){
                    int cur_sum = nums[p1] + nums[p2] + nums[left] + nums[right];
                    if(cur_sum == target){          // 4数和满足要求，将4数插入结果数组中
                        res.push_back({nums[p1], nums[p2], nums[left], nums[right]});
                        ++left;
                        --right;
                        while(left < right && nums[left] == nums[left - 1]){
                            ++left;                 // 确保 nums[left] 改变了，防止重复
                        }
                        while(left < right && nums[right] == nums[right + 1]){
                            --right;                // 确保 nums[right] 改变了，防止重复
                        }
                    }else if(cur_sum > target){     // 大于目标值，需要减小和的值
                        --right;
                    }else{                          // 小于目标值，需要增大和的值
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> res = s.fourSum(nums, 0);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << ',';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
