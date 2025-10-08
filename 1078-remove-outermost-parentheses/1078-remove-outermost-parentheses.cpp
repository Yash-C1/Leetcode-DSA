#include <string>

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int counter=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') counter++;
            else counter--;
            if(counter==1 && s[i]=='(') continue;
            else if(counter==0 && s[i]==')') continue;
            else ans+=s[i];
        }
        return ans;
    }
};