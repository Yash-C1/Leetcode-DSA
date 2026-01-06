class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()) return "0";
        stack<char>st;
        for(int i=0;i<num.length();i++){
            char digit = num[i];
            while(k>0 && !st.empty() && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        string ans = "";
        
        while(k>0) {
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        while(ans.size()!=0 && ans.back()=='0') ans.pop_back();

        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};