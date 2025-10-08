class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakpoint = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                breakpoint = i-1;
                break;
            }
        }
        if(breakpoint==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                swap(nums[breakpoint],nums[i]);
                break;
            }
        }

        sort(nums.begin()+breakpoint+1,nums.end());

    }
};