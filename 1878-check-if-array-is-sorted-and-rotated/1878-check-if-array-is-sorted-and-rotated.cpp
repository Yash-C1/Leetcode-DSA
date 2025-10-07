class Solution {
public:
    bool check(vector<int>& nums) {
        bool breakpoint = false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(breakpoint) return false;
                else breakpoint = true;
            }
        }
        if(breakpoint){
            if(nums[0]>=nums[nums.size()-1]) return true;
            else return false;
        }

        return true;
    }
};