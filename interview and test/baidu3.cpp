#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

// ̰�� + ������
void calMaxNum(int match_num, int digit_types, map<int, int> digits) {
    vector< vector<int> > dp(digit_types + 1, vector<int> (match_num + 1, 0));
    map<int, int>::reverse_iterator iter = digits.rbegin();
    vector<vector<string>> res_str(digit_types + 1, vector<string> (match_num + 1, ""));  // ���ڴ�������
    for(int i = 1; iter != digits.rend() && i <= digit_types; ++iter, ++i) {
        for(int j = 1; j <= match_num; j++) {
            if(iter->second > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max( dp[i - 1][j], dp[i - 1][j - iter->second]*10 + iter->first );
            }
            cout << " dp[" << i << "][" << j << "] " << dp[i][j] << endl;

        }
    }
    cout << dp[match_num][digit_types] << endl;
}
int main() {
    int n, m;  // n ����� m ������
    int nums_map[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    cin >> n >> m;
    map<int, int> digits;       // �������ּ������������ value -> cost
//    vector<int> digits_cost(m + 1, 0);
//    vector<int> digits_value(m + 1, 0);
    for(int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        digits[t] = nums_map[t];
    }
//    map<int, int>::reverse_iterator iter = digits.rbegin();
//    for(; iter != digits.rend(); iter++) {
//        cout << iter->first << " -> "  << iter->second << endl;
//    }
    calMaxNum(n, m, digits);
    return 0;
}
