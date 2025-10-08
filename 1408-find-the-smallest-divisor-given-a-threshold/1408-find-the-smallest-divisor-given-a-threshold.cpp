class Solution {
public:
    int find_maxi(vector<int>& nums){
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }

    bool check_possiblity(vector<int>& nums, int threshold, int mid){
        float ans = 0;
        for(int i=0;i<nums.size();i++){
            float numerator = nums[i];
            float denom = mid;
            ans += ceil(numerator/denom);
        }
        return ans<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = find_maxi(nums);
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            bool possible = check_possiblity(nums,threshold,mid);
            if(possible){
                ans = mid;
                end = mid -1;
            }else start = mid+1;
        }
        return ans;
    }
};