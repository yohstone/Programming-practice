#include<vector>
#include<iostream>
#include<map>
using namespace std;

/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	int len = nums.size();
        vector<int> res(2);
        map<int,int> hashmap;
        map<int,int>::iterator iter;
        for(int i = 0; i < len; i++){
        	iter = hashmap.find(target - nums[i]);
            if(iter != hashmap.end()){
                res[0] = iter->second;
                res[1] = i;
                break;
            }else{
                hashmap[nums[i]] = i;
            }
		}
        return res;
    }

};

int main(){
	int a[4] = {2,7,11,15};
	vector<int> nums(a, a + 4);
	int target = 18;
	vector<int> res;
	Solution *s = new Solution;
	res = s->twoSum(nums, target);
	cout << res[0] << " " << res[1] << endl;
	return 0;
}
