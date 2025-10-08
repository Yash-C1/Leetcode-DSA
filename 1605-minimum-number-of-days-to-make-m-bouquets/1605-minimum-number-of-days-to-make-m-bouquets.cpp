class Solution {
public:
    int get_max(vector<int>& bloomDay){
        int maxi = INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi = max(maxi,bloomDay[i]);
        }
        return maxi;
    }

    bool check_possiblity(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int ans = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
                if(count==k){
                    ans++;
                    count = 0;
                }
            }else{
                count = 0;
            }
        }  
        return ans>=m;  
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = get_max(bloomDay);
        if((long long)m*k>(long long)bloomDay.size()) return -1;
       
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            bool possiblity = check_possiblity(bloomDay,mid,m,k);
            if(possiblity){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};