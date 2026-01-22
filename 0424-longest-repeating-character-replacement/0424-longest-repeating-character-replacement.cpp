class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int max_len = 0;
        int max_freq = 0;
        int l = 0;
        int r = 0;
        while(r<s.size()){
            hash[s[r]-'A']++;
            max_freq = max(max_freq, hash[s[r]-'A']);
            if((r-l+1) - max_freq > k) {
                hash[s[l]-'A']--;
                l++;
                max_freq = 0;
                for(int i=0;i<hash.size();i++){
                    max_freq = max(max_freq, hash[i]);
                }
            }
            max_len = max(max_len, r-l+1);
            r++;
        }
        return max_len;
    }
};