class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int>& candidates, int target, vector<int> &op, int index, int sum){
        if(index==candidates.size()){
            if(sum==target) ans.push_back(op);
            return;
        }
        if(sum>target) return;
       
        op.push_back(candidates[index]);
        helper(ans,candidates, target, op, index, sum+candidates[index]);
        op.pop_back();
        helper(ans,candidates, target, op, index+1, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        int index = 0;
        int sum = 0;
        helper(ans,candidates,target,op,index,sum);
        return ans;
    }
};