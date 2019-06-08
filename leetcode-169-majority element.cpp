#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.
//
//Example 1:
//
//Input: [3,2,3]
//Output: 3
//Example 2:
//
//Input: [2,2,1,1,1,2,2]
//Output: 2



class Solution{
public:
    // 方法1 先排序 后取中间值
    int majorityElement1(vector<int>& nums){
        sort(nums.begin(), nums.end());
        return nums[ nums.size()/2 ];

    }
    // 方法2 栈 栈为空或等于栈顶入栈，不等于栈顶时出栈
    int majorityElement2(vector<int>& nums){
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            if(st.empty() || st.top() == nums[i]){
                st.push(nums[i]);

            }else{
                st.pop();
            }
        }
        return st.top();
    }

    // 方法3 计数抵消 count初始为1，currNum为第一个数，当下一个组等于currNum时count+1，不相等时count-1，count=0时更换currNum为当前数，最终的currNum则为众数
    int majorityElement3(vector<int>& nums){
        int count=1;
        int currNum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == currNum)
                count++;
            else{
                count--;
                if(count == 0){
                    currNum = nums[i];
                    count = 1;
                }
            }
        }
        return currNum;

    }
    // 方法4 map 利用map的关联容器以及key唯一的特性， key为nums里的每个数，value为每个数出现的次数
    int majorityElement4(vector<int>& nums){
        map<int, int> numsMap;
        // 统计各数出现次数
        for(int i=0; i<nums.size(); i++){
            numsMap[nums[i]] ++;
        }
        map<int, int>::iterator iter;
        int maxCountNum = 0, count = 0;
        // 寻找众数
        for(iter = numsMap.begin(); iter != numsMap.end(); iter++){
            //cout<< iter->first << " - " << iter->second <<endl;
            if(iter->second > count){
                maxCountNum = iter->first;
                count = iter->second;
            }
        }
        return maxCountNum;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement4(nums) << endl;
    return 0;
}
