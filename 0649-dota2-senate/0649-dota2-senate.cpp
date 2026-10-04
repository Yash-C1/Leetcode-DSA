class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        int cnt = 1;
        int i = 0;
        char prev = senate[0];
        while (cnt <= n){
            if(i < n-1) i++;
            else i = 0;
            if (senate[i] == 'X') continue;
            if (senate[i] == prev) cnt++;
            else{
                cnt--;
                if (cnt >= 0) senate[i] = 'X';
            }

            if (cnt < 0) {
                cnt = 1;
                prev = senate[i];
            }
        }
        return prev == 'R' ? "Radiant" : "Dire";
    }
};