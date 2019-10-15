#include<iostream>
#include<vector>
using namespace std;

/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 * Example:
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */


class Solution{
public:
    // 方法1：暴力法，易超时
    int maxArea1(vector<int>& height){
        int len = height.size();
        int res = 0;
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                int area = min(height[i], height[j]) * (j - i);   // 当前面积
                res = max(res, area);
            }
        }
        return res;
    }


    // 方法2：双指针法
    // 使用首尾两个指针，从外向内遍历，每次向里移动高度较小的指针。
    int maxArea2(vector<int>& height){
        int len = height.size();
        int res = 0;
        int left = 0, right = len - 1;
        while(left != right){
            int area = min(height[left], height[right]) * (right - left);  // 当前面积
            res = max(res, area);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea2(height) << endl;
    return 0;
}
