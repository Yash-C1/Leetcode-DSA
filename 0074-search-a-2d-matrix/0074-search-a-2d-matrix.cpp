class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row_start = 0;
        int row_end = m-1;
        int row = -1;
        while(row_start<=row_end){
            int row_mid = (row_start+row_end)/2;
            if(target>=matrix[row_mid][0] && target<=matrix[row_mid][n-1]){
                row = row_mid;
                break;
            }else if(target<matrix[row_mid][0]) row_end = row_mid -1;
            else if(target>matrix[row_mid][n-1]) row_start = row_mid+1;
        }

        if(row==-1) return false;

        int col_start = 0;
        int col_end = n-1;
        int col = -1;
        while(col_start<=col_end){
            int col_mid = (col_start+col_end)/2;
            if(matrix[row][col_mid]==target){
                col = col_mid;
                break;
            }else if(matrix[row][col_mid]>target) col_end = col_mid -1;
            else col_start = col_mid+1;
        }

        if(col==-1) return false;

        return true;

    }
};