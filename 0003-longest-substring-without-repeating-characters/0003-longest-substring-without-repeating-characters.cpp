class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if (s=="") return ans;
        unordered_map<char,int> mpp;
        int i = 0;
        int j = 0;
        while(j<=s.length()-1){
            mpp[s[j]]++;
            if(mpp[s[j]]==2){
                while(i<=j && mpp[s[j]]!=1){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0) mpp.erase(s[i]);
                    i++;
                }
            }else{
                ans = max(ans, j-i+1);
            }
            j++;
        }

        return ans;
    }
};