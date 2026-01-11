class Solution {
private:
    void calculate_nse(vector<int>&heights, vector<int>&nse){
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) nse[i]=heights.size();
            else nse[i] = st.top();
            st.push(i);
        }
    }

    void calculate_pse(vector<int>&heights, vector<int>&pse){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i] = st.top();
            st.push(i);
        }
    }

    int get_max(vector<int> heights){
        int max_area = 0;
        vector<int> nse(heights.size(),0);
        vector<int> pse(heights.size(),0);

        calculate_nse(heights,nse);
        calculate_pse(heights,pse);

        for(int i=0;i<heights.size(); i++){
            int area = heights[i] * (nse[i]-pse[i]-1);
            max_area = max(area,max_area);
        }   
        return max_area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int cols = matrix[0].size();
        int rows = matrix.size();
        vector<vector<int>> height(rows, vector<int>(cols, 0));
        
        for(int i = 0; i < cols; i++){
            int sum = 0;
            for(int j = 0; j < rows; j++){
                sum = sum + (matrix[j][i]-'0');
                if(matrix[j][i]=='0'){
                    height[j][i] = 0;
                    sum=0;
                }
                height[j][i] = sum;
            }
        }

        for(int i = 0; i < rows; i++) {
            int max_area = get_max(height[i]);
            ans = max(ans,max_area);
        }

        return ans;
    }
};