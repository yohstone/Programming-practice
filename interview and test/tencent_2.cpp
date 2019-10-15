#include<iostream>
#include<cmath>
using namespace std;

long long calMinWorkTime(long long workersNum, long long totalTime){
    double groupNum = workersNum / 2;
    double averageTime = double(totalTime) / groupNum;
    //long long res = static_cast<long long> (averageTime + 0.5);
    return ceil(averageTime);
}

int main(){
    int n;  // 行数
    long long totalTime = 0;  // 总的拖延时间
    long long M = 0;          // 员工总数
    cin >> n;
    while(n--){
        long long x, y;       // x 名员工的拖延时间为 y
        cin >> x >> y;
        totalTime = totalTime + x * y;
        M += x;
    }
    cout << calMinWorkTime(M, totalTime) << endl;
    return 0;
}
