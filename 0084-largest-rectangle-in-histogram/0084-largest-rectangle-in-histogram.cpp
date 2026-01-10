class Solution {
private:
    void calculate_nse(vector<int> &heights, vector<int> &nse){
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) nse[i] = heights.size();
            else nse[i] = st.top();
            st.push(i);
        }
    }

    void calculate_pse(vector<int> &heights, vector<int> &pse){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector<int> nse(n,0);
        vector<int> pse(n,0);

        calculate_nse(heights,nse);
        calculate_pse(heights,pse);

        for(int i=0;i<n;i++){
            int val = (nse[i] - pse[i] - 1) * heights[i];
            ans = max(ans,val);
        }

        return ans;
    }
};