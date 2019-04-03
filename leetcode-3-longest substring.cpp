//����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//����: "pwwkew"
//���: 3
//����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
//     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
 

#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	
	//����2����������1
	//s[i] �� s[j]�ظ�ʱ��i����һλ 
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
    
	//����3����������2
	//s[i] �� s[j]�ظ�ʱ��i����j 
    int lengthOfLongestSubstring3(string s) {
		map<char, int> substr,t;//��¼�Ӵ��ַ��Լ��ַ���λ�� 
		int n = s.length();
        int i=0,res=0,j=0;
        for( ;j< n;j++){
        	map<char,int>::iterator x = substr.find(s[j]);
        	if( x != substr.end()){
        		//cout<< x->first << "--" << x->second <<endl; 
        		i = max(x->second, i);//�ظ��ַ���һ��λ�ú͵�ǰi�Ƚ� 
        		substr[s[j]] = j+1;   	//�����ظ��ַ���λ��������ȡ�����λ��	
			}
			res = max(res, j-i+1);
        	substr.insert( pair<char, int>(s[j], j+1 ) );//�洢�ַ�����λ�� 
		} 
//			t = substr;
//			while(t.begin() != t.end()){
//				cout<< t.begin()->first << "--" << t.begin()->second <<endl; 
//				t.erase(t.begin());
//			}
//			cout << endl;
		return res;
    }
    
	//����4���ַ��� 
	//˼·���Ż��滬����������  �� s[i] �� s[j]�ظ�ʱ��i����j 
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
