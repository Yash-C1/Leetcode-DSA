class Solution {
public:
    bool check_palindrome(string s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // void solve(string s, vector<string> op, vector<vector<string>>& ans){
    //     if(s.empty()){
    //         for(auto &str : op)
    //             if(!check_palindrome(str)) return;
    //         ans.push_back(op);
    //         return;
    //     }

    //     string s1 = s;
    //     string last = op.back();
    //     last.push_back(s[0]);
    //     op.pop_back();
    //     op.push_back(last);
    //     s1.erase(s1.begin());
    //     solve(s1, op, ans); // extend last substring

    //     // backtrack and start new substring
    //     last.pop_back();
    //     op.pop_back();
    //     op.push_back(last);
    //     op.push_back(string(1, s[0]));
    //     solve(s1, op, ans); // new substring
    // }

    void solve(string s, vector<string> op, vector<vector<string>>& ans, int index){
        if(index==s.length()){
            ans.push_back(op);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(check_palindrome(s.substr(index,i - index + 1))){
                op.push_back(s.substr(index,i - index + 1));
                solve(s, op, ans, i+1);
                op.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        vector<string> op;
        solve(s, op, ans, 0);
        return ans;
    }
};


