class Solution {
public:
    void helper(vector<int>& nums, vector<int>ds, vector<vector<int>>&ans, int index){
        if(index==nums.size()){
            ans.push_back(ds);
            return;
        }

        int curr = nums[index];
        ds.push_back(curr);
        helper(nums,ds,ans,index+1);
        ds.pop_back();

        while(index<nums.size() && nums[index]==curr) index++;
        helper(nums,ds,ans,index);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        helper(nums,ds,ans,0);
        return ans;
    }
};