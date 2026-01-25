class Solution {
private:
    int helper(vector<int>& nums, int k){
        // This function returns number of subarrays with <= k different integers.
        if(k==0) return 0;
        unordered_map<int,int> mpp;
        int diff = 0;
        int cnt = 0;
        int l = 0;
        int r = 0;

        while(r<nums.size()){
            if(mpp.find(nums[r])==mpp.end()) diff++;
            while(diff>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    diff--;
                    mpp.erase(nums[l]);
                }
                l++;
            }
            mpp[nums[r]]++;
            cnt += r-l+1;
            r++;
        }

        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};