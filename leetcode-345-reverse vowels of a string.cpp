#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            while(!(vowels.find(s[i]) != vowels.end()) && i < j){
                i++;
            }
            while( i < j && !(vowels.find(s[j]) != vowels.end()) ){
                j--;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main() {
    return 0;
}
