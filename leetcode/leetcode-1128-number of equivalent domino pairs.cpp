#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/* Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.
 *
 * Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
 *
 * Example 1:
 *
 * Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * Output: 1
 *
 * Constraints:
 *
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 */

 class Solution{
 public:
     // 将 vector 容器中的每对牌进行排序，然后将排序好的牌对插入一个 map 容器中，牌对作为 map 的“键”，其“值”为等价牌对的对数，
     // 统计等价牌对数量结束后，遍历 map 容器，计算每种等价牌对的组合数，累加返回。
     int numEquivDominoPair(vector<vector<int>>& dominoes){
        int len = dominoes.size();
        int res = 0;
        map<vector<int>, int>  dominoes_count;

        for(auto d : dominoes){                 // 遍历牌对数据，统计等价牌对的数量，并插入 map
            sort(d.begin(), d.end());           // 牌对排序
            dominoes_count[d]++;                // 牌对对应的数量+1
        }

        for(auto num : dominoes_count){         // 计算结果
            int n = num.second;
            if( n > 1){
                res += n * (n - 1) / 2;         // 每种牌对的等价数量 = C(2, n)
            }

        }
        return res;
     }
 };

int main(){
    vector<vector<int>> dominoes = {{1,2}, {2,1}, {1,2}, {5,6} };
    Solution s;
    cout << s.numEquivDominoPair(dominoes) << endl;
    return 0;
}
