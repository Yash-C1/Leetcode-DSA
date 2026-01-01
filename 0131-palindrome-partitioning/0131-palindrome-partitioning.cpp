class Solution {
private:
    bool check_palindrome(string s){
        int i=0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans, vector<string>&ds, string s, int index){
        if(index==s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<s.length();i++){
            string temp = s.substr(index,i-index+1);
            if(check_palindrome(temp)){
                ds.push_back(temp);
                helper(ans,ds,s,i+1);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        helper(ans,ds,s,0);
        return ans;
    }
};