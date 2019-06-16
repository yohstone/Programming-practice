#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keybord = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> res;
        int flag = 0;
        for(int i=0; i<words.size(); i++){
                string temp = words[i];
            for(int j=0; j<temp.length(); j++){
                if( temp[j]>='A' && temp[j] <= 'Z'){
                    temp[j] += 32; // 转为小写
                }
                if( keybord[0].find( temp[j] ) != -1 || keybord[1].find( temp[j] ) != -1 || keybord[2].find( temp[j] ) != -1){
                    flag = 1;
                }else{
                    flag = 0;
                }
            }
            if( flag == 1){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
int main(){

    return 0;
}
