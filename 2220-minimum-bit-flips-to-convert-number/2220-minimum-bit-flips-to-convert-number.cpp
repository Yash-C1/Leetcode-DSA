class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = start^goal;
        int cnt = 0;
        while(result>0){
            if(result & 1) cnt++;
            result = result >> 1;
        }
        return cnt;
    }
};