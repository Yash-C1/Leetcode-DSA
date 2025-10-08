class Solution {
public:
    long long calculate_hours(int mid, vector<int>piles){
        long long return_ans = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid == 0) return_ans+= (piles[i]/mid);
            else return_ans+= (piles[i]/mid)+1;
        }
        return return_ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }

        int start = 1;
        int end = maxi;

        int ans = -1;

        while(start<=end){
            int mid = start + (end - start)/2;
            long long req = calculate_hours(mid, piles);
            if(req<=(long long)h){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};