#include<iostream>
using namespace std;

/**
* 给定零食种类数 N、每种零食的价格数组 c_i[] 、客户所喜爱零食的种类 M 及喜爱程度高到低排序的数组 pri[]。求出在花光指定开销 V 的情况下，购买零食的方案数。
* 要求受喜爱程度高的零食数量要比喜爱程度低的零食数量多。
*/

// V 开销 ，N 所有零食种类，c_i 所有零食价格表， M 特别喜欢的零食种类数， pri 喜欢的零食喜欢程度表 降序排列
// 代码还有点问题，这个思路也不行，貌似应该使用贪心+背包。待完善，
int divide(int V, int N, int c_i[], int M, int pri[]) {
    int c_num[200] = {0};  // 所有零食中每种零食购买数量数组
    long long num = 0;     // 方案数
    int sum = 0;           // 统计当前花销
    int low = 0;           // 记录不喜欢的零食能购买的最大数量（因为数量不能大于喜欢零食的数量）
    int index = 0;
    int highprice = 0;
    int i = 0;
    int nonpri[200] = {0};        // 不喜欢的零食数组
    int j = 0;
    for (i = 0; i < M; i++) {     // 当所有喜欢的零食都买的时候的最低消费
        c_num[pri[i] - 1] = M - i;
        highprice += c_i[pri[i] - 1] * c_num[pri[i] - 1];
    }
    if (highprice == V) {
        cout << ++num << endl;
        return 0;
    }
    int nValue = 0;
    for (i = 0; i < N; i++) {     // 记录不是喜欢的零食的下标
        int flag = 0;
        for (j = 0; j < M; j++) {
            if (i + 1 == pri[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            nonpri[nValue] = i + 1;
            nValue++;
        }
    }
    c_num[pri[0] - 1] = V / c_i[pri[0] - 1];    // 最喜欢的零食购买数量
    sum += c_num[pri[0] - 1] * c_i[pri[0] - 1]; // 加上最喜欢的零食的花销
    index++;    // 所喜欢零食种类数组的下标，此时++表示开始遍历下一种喜欢的零食
    while (sum <= V) {
        if (sum == V) {
            num++;
        }
        sum += c_i[pri[index] - 1];     // 加上当前喜欢的零食的价格
        c_num[pri[index] - 1]++;        // 相应的购买数量加1
        if (sum > V) {                  // 花费超过的时候，考虑减去当前喜爱的零食数量
            if (c_num[pri[index]] + 1 == c_num[pri[index - 1]]) { // 当前喜欢的零食的数量比上一种喜欢零食的数量少1
                sum = sum - c_i[pri[index] - 1];
                c_num[pri[index]]--;    // 当前喜欢零食的数量减1
            } else {
                if (index < M - 1) {    // 喜欢的零食还没遍历完
                    index++;
                } else {                // 喜欢的零食遍历完了，开始添加不喜欢的
                    low = c_num[pri[M - 1] - 1] - 1; // 不喜欢的零食最多能购买的数量为 最后一个喜欢的零食的购买数量 - 1
                    if (low == -1) {
                        break;
                    }
                    int comIndex = 0;   // 不喜欢的零食数组的下标
                    while (sum <= V) {
                        if (sum == V) {
                            num++;
                        }
                        if (c_num[nonpri[comIndex] - 1] + 1 == low) {  // 当前零食的数量已达最大值
                            comIndex++; // 遍历下一零食
                        } else {
                            sum += c_i[nonpri[comIndex] - 1];
                            c_num[nonpri[comIndex] - 1]++;
                        }
                        if (sum > V) {
                            sum = sum - c_i[nonpri[comIndex] - 1];
                            c_num[nonpri[comIndex] - 1]--;
                        }
                    }
                }
            }
        }
    }
    cout << (num % 10000007) << endl;
    return 0;
}


int main() {
    int V = 0, N = 0;     // V 开销 ，N 零食种类
    int c_i[200] = {0};   // 零食价格数组
    int M;                // 特别喜欢的零食种类
    int pri[200] = {0};   // 零食喜爱程度数组
    cin >> V >> N;
    for (int i = 0; i < N; i++) {
        cin >> c_i[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> pri[i];
    }
    divide(V, N, c_i, M, pri);
    return 0;
}
