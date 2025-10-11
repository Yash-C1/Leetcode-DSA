class Solution {
public:

    int expand(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }

    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;

        for(int i=0;i<s.size();i++){
            int single_expand = expand(s,i,i);
            int double_expand = expand(s,i,i+1);
            int maxi = max(single_expand,double_expand);

            if(maxi>end-start+1){
                start = i - (maxi - 1) / 2;
                end = i + maxi / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};