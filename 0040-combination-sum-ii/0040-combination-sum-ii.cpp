class Solution {
public:

    void helper(vector<int>& candidates, int target, int index, int sum, vector<int>& op, vector<vector<int>> &ans){
        
        if(sum==target){
            ans.push_back(op);
            return;
        }

        if (sum > target || index >= candidates.size()) return;

        int curr = candidates[index];
        op.push_back(curr);
        helper(candidates, target, index+1, sum+curr, op, ans);
        op.pop_back();

        while(index < candidates.size() && candidates[index]==curr) index++;
        helper(candidates, target, index, sum, op, ans);

    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> op;
        int index = 0;
        int sum = 0;
        helper(candidates, target, index, sum, op, ans);
        return ans;
    }
};