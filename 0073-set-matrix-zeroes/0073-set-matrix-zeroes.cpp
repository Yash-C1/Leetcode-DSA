class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int zero_row_present = false;
        int zero_col_present = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<m;i++){
            if(matrix[i][0]==0) zero_col_present = true;
        }
        for(int i = 0;i<n;i++){
            if(matrix[0][i]==0) zero_row_present = true;
        }
        for(int i=1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int j=1;j<m;j++){
            if(matrix[j][0]==0){
                for(int i=0;i<n;i++){
                    matrix[j][i] = 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            if(matrix[0][i]==0){
                for(int j=0;j<m;j++){
                    matrix[j][i] = 0;
                }
            }
        }

        if(zero_row_present){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0;
            }
        }

        if(zero_col_present){
            for(int j=0;j<m;j++){
                matrix[j][0] = 0;
            }
        }


    }
};