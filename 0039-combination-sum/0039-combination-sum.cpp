class Solution {
private:
    void helper(set<vector<int>> &temp, vector<int>& candidates, int target, vector<int> &op, int index, int sum){
        if(index==candidates.size()){
            if(sum==target) temp.insert(op);
            return;
        }
        if(sum>target) return;
        vector<int> op1 = op;
        vector<int> op2 = op;
        op1.push_back(candidates[index]);
        helper(temp,candidates, target, op1, index, sum+candidates[index]);
        helper(temp,candidates, target, op2, index+1, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> temp;
        vector<vector<int>> ans;
        vector<int> op;
        int index = 0;
        int sum = 0;
        helper(temp,candidates,target,op,index,sum);

        for (auto& x : temp)
            ans.push_back(x);

        return ans;
    }
};