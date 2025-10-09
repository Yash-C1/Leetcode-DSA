class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp;
        unordered_map<char,char> mpp2;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                if(mpp[s[i]]!=t[i]) return false;
            }else{
                mpp[s[i]] = t[i];
            }

            if(mpp2.find(t[i])!=mpp2.end()){
                if(mpp2[t[i]]!=s[i]) return false;
            }else{
                mpp2[t[i]] = s[i];
            }
        }

        return true;

    }
};