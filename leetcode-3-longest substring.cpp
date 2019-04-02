#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int max_len=1,curr_len=1;
    	char last_char = s[0];
        for(int i=1;i<s.length(); i++){
        	 if(s[i] - last_char != 0){
        	 	curr_len ++;
			 }else{
			 	
			 }
		}
    }
};
int main(){
	
	return 0;
} 
