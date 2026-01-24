class Solution {
private:
    int helper(vector<int> &nums, int k){
        // This function returns number of subarrays with less than or equal to k odd numbers in it.
        int cnt = 0;
        int odds = 0;
        int l = 0;
        int r = 0;
        while(r<nums.size()){
            if(nums[r]%2!=0) odds++;
            while(odds>k){
                if(nums[l]%2!=0) odds--;
                l++;
            }
            if(odds <= k) cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};