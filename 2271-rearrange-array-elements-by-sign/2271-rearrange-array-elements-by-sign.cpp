class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int i=0; // store all positive numbers
        int j=1; // store all negative numbers
        for(int x=0;x<nums.size();x++){
            if(nums[x]>0){
                ans[i] = nums[x];
                i+=2;
            }else{
                ans[j] = nums[x];
                j+=2;
            }
        }

        return ans;
    }
};