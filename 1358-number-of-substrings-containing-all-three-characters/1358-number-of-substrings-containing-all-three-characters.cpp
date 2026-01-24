class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int freq[3] = {-1,-1,-1};

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a'] = i;
            cnt += 1+min({freq[0],freq[1],freq[2]});
        }

        return cnt;
    }
};