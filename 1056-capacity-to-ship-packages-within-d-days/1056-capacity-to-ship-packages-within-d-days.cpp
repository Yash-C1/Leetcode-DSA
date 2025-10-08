class Solution {
public:
    bool check_possiblity(vector<int> &weights, int days, int mid){
        int ans = 0;
        int counter = 1;
        for(int i=0;i<weights.size();i++){
            if(ans+weights[i]>mid){
                ans = weights[i];
                counter++;
            }else{
                ans+=weights[i];
            }
        }
        return counter <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = INT_MIN;
        int end = 0;
        for(int i=0;i<weights.size();i++){
            start = max(start,weights[i]);
            end+=weights[i];
        }
        int ans = -1;

        while(start<=end){
            int mid = start + (end-start)/2;
            bool possiblity = check_possiblity(weights, days, mid);
            
            // this will return true if the days needed to ship all packets with this capacity is less than / equal to days.
            if(possiblity){
                ans = mid;
                end = mid - 1;
            }else start = mid+1;
        }
        return ans;
    }
};