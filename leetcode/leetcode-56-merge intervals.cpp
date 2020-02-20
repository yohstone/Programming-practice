#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


    // 给出一个区间的集合，请合并所有重叠的区间。

    // Given a collection of intervals, merge all overlapping intervals.

    // Example 1:

    // Input: [[1,3],[2,6],[8,10],[15,18]]
    // Output: [[1,6],[8,10],[15,18]]
    // Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
    // Example 2:

    // Input: [[1,4],[4,5]]
    // Output: [[1,5]]Å
    // Explanation: Intervals [1,4] and [4,5] are considered overlapping.
    // NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.




class Solution {
public:
    // 方法1：先排序，然后合并区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 0) return res;
        sort(intervals.begin(), intervals.end());
        int i = 0; 
        while(i < n){
            int left = intervals[i][0];     // 当前区间的左边界
            int right = intervals[i][1];    // 当前区间的右边界
            while(i < n - 1 && intervals[i + 1][0] <= right){ // 下一区间的左边界小于当前区间的右边界，有重叠
                right = max(right, intervals[++i][1]);        // 将当前区间的右边界更新为下一区间的右边界
            }
            res.push_back({left, right});   // 与当前区间有重叠的区间都已合并到 [left, right] 中，添加到结果集合
            ++i;
        }
        return res;
    }
};



int main() {
    Solution s;
    return 0;

}
