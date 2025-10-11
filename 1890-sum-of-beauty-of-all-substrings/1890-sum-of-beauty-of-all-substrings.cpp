class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0;i<s.size()-1;i++){
            unordered_map<char,int>mpp;
            mpp[s[i]]++;
            for(int j=i+1;j<s.size();j++){
                mpp[s[j]]++;
                if(mpp.size()==1) continue;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto it:mpp){
                    maxi = max(maxi,it.second);
                    mini = min(mini,it.second);
                }
                ans+= (maxi-mini);
            }
        }
        return ans;
    }
};