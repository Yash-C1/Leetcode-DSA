class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int smallest = INT_MAX;
        for(int i=0;i<prices.size();i++){
            smallest = min(smallest,prices[i]);
            maxi = max(maxi, prices[i]-smallest);
        }
        return maxi;
    }
};