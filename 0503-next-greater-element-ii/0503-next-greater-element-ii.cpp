class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }

        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }

            if(i<n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }

            st.push(nums[i]);
        }

        return ans;
    }
};