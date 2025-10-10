class Solution {
public:
    int maxDepth(string s) {
        int counter = 0;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') counter++;
            else if(s[i]==')') counter--;
            ans = max(ans,counter);
        }
        return ans;
    }
};