#include<vector>
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	int len = nums.size();
    	map<int,int> hashmap;
    	map<int, int>::iterator iter;
        for(int i =0; i<len ; i++){
        	iter = hashmap.find(target-nums[i]);
        	if( iter != hashmap.end()){
        		cout << iter->second << "  " << i ;
        		break;
			}else{
				hashmap[nums[i]] = i;
			}
		}
    }

};

int main(){
	int a[4] = {2,7,11,15};
	vector<int> nums(a, a+4);
	int target = 9;
	Solution *s = new Solution;
	s->twoSum(nums, target);
	return 0;
}
