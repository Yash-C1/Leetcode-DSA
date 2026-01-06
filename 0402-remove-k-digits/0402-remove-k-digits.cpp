class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()) return "0";
        stack<int>st;
        for(int i=0;i<num.length();i++){
            int digit = num[i] - '0';
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
            ans+=(char)(st.top()+'0');
            st.pop();
        }

        while(ans.size()!=0 && ans.back()=='0') ans.pop_back();

        reverse(ans.begin(),ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};