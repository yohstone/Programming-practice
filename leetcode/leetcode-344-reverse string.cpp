//
//  leetcode-344-reverse string.cpp
//  leetcode-code
//
//  Created by Steve Stone on 2019/5/30.
//  Copyright © 2019年 Steve Stone. All rights reserved.
//

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void reverseString(vector<char>& s) {
        double len = s.size();
        cout << len/2.0 << endl;
        //中位数两边互换
        for( int i = 0; i < len/2.0; i++){
            char temp ;
            temp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = temp;
        }
    }
};
int main(){
    vector<char> str = {};
    Solution s;
    s.reverseString(str);
    for (int i=0; i<str.size(); i++) {
        cout << str[i] << endl;
    }
    
    return 0;
}
