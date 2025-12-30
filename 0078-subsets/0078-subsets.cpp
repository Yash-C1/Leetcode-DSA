class Solution {
public:
    void helper(vector<int> nums, vector<int> temp, vector<vector<int>>& ans) {
        if (nums.empty()) {
            ans.push_back(temp);
            return;
        }

        int ele = nums.back();
        nums.pop_back();

        helper(nums, temp, ans);

        temp.push_back(ele);
        helper(nums, temp, ans);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, temp, ans);
        return ans;
    }
};