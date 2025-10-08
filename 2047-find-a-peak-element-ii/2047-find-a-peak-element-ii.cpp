class Solution {
public:
    int maxElement(vector<vector<int>>& arr, int col) {
        int n = arr.size();
        int max_val = INT_MIN;
        int index = -1;

        // Iterate through each row to find the maximum element 
        // in the particular column
        for (int i = 0; i < n; i++) {
            if (arr[i][col] > max_val) {
                max_val = arr[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            int max_index = maxElement(mat,mid);
            int left = -1;
            int right = -1;
            if(mid-1>=0) left = mat[max_index][mid-1];
            if(mid+1<n) right = mat[max_index][mid+1];
            if(mat[max_index][mid]>left && mat[max_index][mid]>right) return {max_index,mid};
            else if(mat[max_index][mid]<left) high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};