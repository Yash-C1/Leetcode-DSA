class Solution {
public:
    int helper(vector<int>& nums, int start, int end, int target){
        int mid = (start+end)/2;
        if(start>end) return -1;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) end = mid-1;
        else start = mid+1;
        return helper(nums, start, end, target);
    }

    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ans = helper(nums, start, end, target);
        return ans;
        
        
    }
};