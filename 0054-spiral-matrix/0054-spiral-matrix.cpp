class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int right = n-1;
        int left = 0; // 0 to n
        int up = 0;  // 0 to m
        int down = m-1;

        while(left<=right && up<=down){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[up][i]);
            }
            up++;
            for(int i=up;i<=down;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(up<=down){
                for(int i = right;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if(left<=right){
                for(int i = down;i>=up;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};