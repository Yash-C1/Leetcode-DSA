class Solution {
public:
    void generate(vector<string> &ans, int n, string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }

        int counter = 0;
        int i = 0;
        int maxi = 0;
        while(i<s.size()){
            if(s[i]=='(') {
                counter++;
                maxi++;
            }
            else counter--;
            i++;
        }
        if(maxi<n) generate(ans,n,s+'(');
        if(counter>0) generate(ans,n,s+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generate(ans,n,s);
        return ans;
    }
};