#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//    现在你总共有 n 门课需要选，记为 0 到 n-1。
//
//    在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
//
//    给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
//
//    示例 1:
//
//    输入: 2, [[1,0]]
//    输出: true
//    解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
//    示例 2:
//
//    输入: 2, [[1,0],[0,1]]
//    输出: false
//    解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
//
//    There are a total of n courses you have to take, labeled from 0 to n-1.
//
//    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//    Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?



class Solution {
public:
    // 方法1 ： 拓补排序
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses <= 0){
            return false;
        }
        int prereq_len = prerequisites.size();
        if(prereq_len == 0){
            return true;
        }
        vector<int> in_dgree(numCourses, 0);
        for(auto p : prerequisites){    // 计算每个课程的入度
            ++in_dgree[p[0]];
        }
        queue<int> que;                 // 通过队列暂存求拓补排序的每一步之后入度为 0 的课程
        for(int i = 0; i < numCourses; ++i){
            if(in_dgree[i] == 0){
                que.push(i);            // 先将初始入度为 0 的课程加入队列
            }
        }

        vector<int> res;
        while(!que.empty()){            // 求拓补排序结果
            int course = que.front();
            que.pop();
            res.push_back(course);
            for(auto p : prerequisites){
                if(p[1] == course){
                    --in_dgree[p[0]];
                    if(in_dgree[p[0]] == 0){
                        que.push(p[0]);
                    }
                }
            }
        }

        return res.size() == numCourses;


    }
};


int main(){
    Solution s;

    return 0;
}
