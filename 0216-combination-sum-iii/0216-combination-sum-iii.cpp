class Solution {
private:
    void helper(vector<int> &nums, vector<vector<int>>&ans, vector<int>&ds, int k, int n, int index, int sum, int size){
        if(size==k && sum==n){
            ans.push_back(ds);
            return;
        }

        if(size>k || index==nums.size() || sum>n) return;

        int curr = nums[index];
        ds.push_back(curr);
        helper(nums,ans,ds,k,n,index+1,sum+curr,size+1);
        ds.pop_back();
        helper(nums,ans,ds,k,n,index+1,sum,size);    
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>ds;
        helper(nums,ans,ds,k,n,0,0,0);
        return ans;
    }
};