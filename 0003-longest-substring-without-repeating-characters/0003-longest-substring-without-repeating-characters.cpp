class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int l = 0;
        int r = 0;
        unordered_map<char,int> mpp;

        while(r<s.length()){
            if(mpp.find(s[r])!=mpp.end()) l = max(l,mpp[s[r]]+1);
            mpp[s[r]] = r;
            max_len = max(max_len, r-l+1);
            r++;
        }
        return max_len;
    }
};