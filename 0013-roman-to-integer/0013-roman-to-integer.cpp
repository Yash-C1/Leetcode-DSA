class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int ans = 0;
        int i=0;
        while(i<s.size()-1){
            if(mpp[s[i+1]]>mpp[s[i]]){
                int diff = mpp[s[i+1]] - mpp[s[i]];
                ans+=diff;
                i++;
            }else ans+=mpp[s[i]];
            i++;
        }

        if(i==s.size()-1) ans+=mpp[s[i]];
        return ans; 
    }
};