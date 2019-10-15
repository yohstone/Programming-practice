#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/* Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * Example 2:
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Note:
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 */

class Solution{
public:
    // 方法1, set法，先用set获取nums1不重复的元素，然后查看nums2中是否存在
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        set<int> numsSet(nums1.begin(), nums1.end());
        vector<int> res;
        for(int i=0; i<nums2.size(); i++){
            // 若存在numsSet中，则添加到res并删除numsSet中的元素，以防重复添加
            if( numsSet.find(nums2[i]) != numsSet.end() ){
                res.push_back(nums2[i]);
                numsSet.erase(nums2[i]);
            }
        }
        return res;
    }
    // 方法2：直接在vector中查找相同元素
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        // 遍历小vector就行
        if( nums1.size() > nums2.size() ){
            swap(nums1, nums2);
        }
        for(int i=0; i<nums1.size(); i++){
            if( find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end() ){
                if( find(res.begin(), res.end(), nums1[i]) == res.end() ){
                    res.push_back(nums1[i]);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1,1,2,2,3,6};
    vector<int> res;
    res = s.intersection2(nums1, nums2);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
