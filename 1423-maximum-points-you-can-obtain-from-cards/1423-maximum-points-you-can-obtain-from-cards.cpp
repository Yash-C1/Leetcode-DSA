class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int s = 0;
        for(int i=0;i<k;i++){
            s+=cardPoints[i];
        }
        ans = s;
        for(int i=k-1;i>=0;i--){
            s -= cardPoints[i];
            s += cardPoints[cardPoints.size()-(k-i)];
            ans = max(ans, s);
        }
        return ans;
    }
};