class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        vector<int> freq2(26,0);
        for(int i=0;i<s.size();i++){
            freq2[t[i]-'a']++;
        }

        return freq==freq2;

    }
};