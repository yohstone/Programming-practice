#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//    假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
//    编写一个算法来重建这个队列。
//
//    注意：
//    总人数少于1100人。
//
//    示例
//
//    输入:
//    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//    输出:
//    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
//    Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k),
//    where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
//    Write an algorithm to reconstruct the queue.
//
//    Note:
//    The number of people is less than 1,100.


class Solution {
public:
    // 按照身高自大到小排序，当身高相同时，前面人的人少的排在前面
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]){
            return a[0] > b[0];
        }else{
            return a[1] < b[1];
        }
    }
    // 方法1：先对身高进行降序排序，当身高相同时，前面人少的排在前面
    // 然后从最高的开始，一个个插入结果数组中
    // 不断从 people 数组里挑出当前身高最高的人 x 出来，插入到 res.
    // 因为此时 res 中每个人的身高都比 x 要高，因此 x 插入的位置，就是看 x 前面应该有多少人就行了。
    // 比如 x 前面有 5 个人，那 x 就插入到队列 res 的第 5 个位置。
    // 时间复杂度 O(nlogn + n) 空间复杂度 O(n)
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        if (people.size() == 0){
            return res;
        }

        sort(people.begin(), people.end(), cmp);    // 排序

//        // 或使用：
//        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
//            if (a[0] > b[0])
//                return true;
//            if (a[0] == b[0] && a[1] < b[1])
//                return true;
//            return false;
//        });

        for (auto person : people) {
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }

};

int main(){
    Solution s;

    return 0;
}
