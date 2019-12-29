#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


//    在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//    示例 1:
//
//    输入: [3,2,1,5,6,4] 和 k = 2
//    输出: 5
//    示例 2:
//
//    输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//    输出: 4
//    说明:
//
//    你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
//
//    Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.




class Solution {
public:
    // 方法1：排序法，问题转换为求第 n - k 个最小的元素
    // 时间复杂度 O(nlogn)  空间复杂度 O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 0 || k > len){
            return 0;
        }
        sort(nums.begin(), nums.end());
        return nums[len - k];
    }
    // 方法2：小顶堆法，维护一个大小为 k 的小顶堆，堆里为当前最大的 k 个数，
    // 当堆的大小大于 k 时弹出堆顶元素
    // 最后堆顶的元素即为第 k 个最大的元素
    // 时间复杂度 O(nlogk)  空间复杂度 O(k)
    int findKthLargest2(vector<int>& nums, int k) {
        int len = nums.size();
        if(len <= 0 || k > len){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> small_heap; // 使用优先队列实现小顶堆
        for(int i = 0; i < len; ++i){
            small_heap.push(nums[i]);
            if(small_heap.size() > k){      // 堆的大小超过 k ，弹出堆顶的最小元素
                small_heap.pop();
            }
        }
        return small_heap.top();
    }

    // 方法3：快速选择法，问题转换为求第 n - k 个最小的元素，
    // 仿照快排，选择一个基准，把小于基准的放在基准左边，大于基准的放在基准右边
    // 然后使用基准的位置与 n - k 进行比较，用于决定继续递归左边还是右边
    int findKthLargest3(vector<int>& nums, int k) {

    }

};
int main(){
    Solution s;
    return 0;
}
