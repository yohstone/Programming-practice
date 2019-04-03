//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	
	//方法2，滑动窗口1
	//s[i] 与 s[j]重复时，i右移一位 
    int lengthOfLongestSubstring2(string s) {
		set<char> substr,t;
		int n = s.length();
        int i=0,res=0,j=0;
        while(i<n && j < n){
        	if(substr.find(s[j]) == substr.end()) {
        		substr.insert(s[j++]);
				res = max(res, j-i);	
			}else{
				substr.erase(s[i++]);			
			}
//			t = substr;
//			while(t.begin() != t.end()){
//				cout << *t.begin();
//				t.erase(t.begin());
//			}
//			cout << endl;
		}

		return res;
    }
    
	//方法3，滑动窗口2
	//s[i] 与 s[j]重复时，i跳到j 
    int lengthOfLongestSubstring3(string s) {
		map<char, int> substr,t;//记录子串字符以及字符的位置 
		int n = s.length();
        int i=0,res=0,j=0;
        for( ;j< n;j++){
        	map<char,int>::iterator x = substr.find(s[j]);
        	if( x != substr.end()){
        		//cout<< x->first << "--" << x->second <<endl; 
        		i = max(x->second, i);//重复字符下一个位置和当前i比较 
        		substr[s[j]] = j+1;   	//更新重复字符的位置索引，取靠后的位置	
			}
			res = max(res, j-i+1);
        	substr.insert( pair<char, int>(s[j], j+1 ) );//存储字符所在位置 
		} 
//			t = substr;
//			while(t.begin() != t.end()){
//				cout<< t.begin()->first << "--" << t.begin()->second <<endl; 
//				t.erase(t.begin());
//			}
//			cout << endl;
		return res;
    }
    
	//方法4，字符集 
	//思路和优化版滑动窗口类似  ， s[i] 与 s[j]重复时，i跳到j 
    int lengthOfLongestSubstring4(string s) {
		int n = s.length();
		int index[128] = {0}; 
        int i=0,res=0,j=0;
        for( ;j< n;j++){
        	i = max(index[s[j]], i);
        	res = max(res, j-i+1);
        	index[s[j]] = j +1;   
        }
		return res;
    }
    
};
int main(){
	Solution a;
	string s = " ";//"abcdaefghaij";
	cout << a.lengthOfLongestSubstring4(s);
	return 0;
} 
