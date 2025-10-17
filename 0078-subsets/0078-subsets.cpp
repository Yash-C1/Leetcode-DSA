class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        helper(nums, i + 1, temp, ans);
        temp.push_back(nums[i]);
        helper(nums, i + 1, temp, ans);
        temp.pop_back();  // backtrack
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, 0, temp, ans);
        return ans;
    }
};