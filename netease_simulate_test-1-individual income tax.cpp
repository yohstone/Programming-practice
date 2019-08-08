#include<iostream>
#include<map>
#include<cmath>
using namespace std;

/**
 * 网易2020校园招聘模拟笔试 - 1
 * 根据汇率表计算个人所得税
 * 思路：
 * 将税率表按照 key = 区间起始金额， value = 区间税率，即 {区间起始金额, 税率} 存入一个 map 中，然后根据个人收入，使用税率表计算个人所得税
 */

// 计算个人所得税，income: 个人收入， taxs: 汇率表
int calTax(int income, map<int, double> &taxs){
    int len = taxs.size();
    if(income <= 5000){
        return 0;
    }
    income  = income - 5000;
    int i   = 0;    // 记录当前为第几个区间
    int res = 0;
    map<int, double>::iterator iter_cur  = taxs.begin();      // 当前区间迭代器
    map<int, double>::iterator iter_next = ++taxs.begin();    // 下一区间迭代器，用于取得下一区间的起始值
    for(; iter_cur != taxs.end(); iter_cur++, iter_next++){   // 遍历汇率表计算当前收入应缴纳的税
        if(income - iter_cur->first <= 0){
            break;
        }else{
            int range_tax;  // 当前区间所需缴纳的税额
            if(income >= iter_next->first && i < len - 1){  // 收入大于当前纳税区间的最大值，即大于下一区间的起始值时。并且当前区间不是最后一个区间
                range_tax = round((iter_next->first - iter_cur->first) * iter_cur->second);  // 直接区间值 * 区间税率
            }else{
                range_tax = round((income - iter_cur->first) * iter_cur->second);            // 收入与区间起始值的差 * 区间税率
            }
            res += range_tax;
            i++;
        }
    }
    return res;
}


int main(){
    int T;
    map<int, double> taxs = {   // 税率表
        {0,     0.03},
        {3000,  0.1},
        {12000, 0.2},
        {25000, 0.25},
        {35000, 0.3},
        {55000, 0.35},
        {80000, 0.45}
    };

    cin >> T;
    while(T--){
        int N;
        int tax;
        cin >> N;
        cout << calTax(N, taxs) << endl;
    }
	return 0;
}





