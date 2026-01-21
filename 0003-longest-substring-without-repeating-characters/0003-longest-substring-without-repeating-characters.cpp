class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int l = 0;
        int r = 0;
        vector<int> hash(256, -1);

        while(r<s.length()){
            if(hash[s[r]]!=-1) l = max(l,hash[s[r]]+1);
            hash[s[r]] = r;
            max_len = max(max_len, r-l+1);
            r++;
        }
        return max_len;
    }
};