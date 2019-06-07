#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution{
public:
    // 方法1 先排序 后取中间值
    int majorityElement1(vector<int>& nums){
        sort(nums.begin(), nums.end());
        return nums[ nums.size()/2 ];

    }
    // 方法2 栈
    int majorityElement2(vector<int>& nums){


    }

    // 方法3 计数抵消
    int majorityElement3(vector<int>& nums){


    }
    // 方法4 map
    int majorityElement4(vector<int>& nums){


    }
};
int main(){
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement1(nums) << endl;
    return 0;
}
