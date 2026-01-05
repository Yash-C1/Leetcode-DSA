class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int width = 0;
        int start = 0;
        int cnt = 0;
        int reverse_cnt = 0;
        stack<int> st;
        int n = height.size();

        for(int i=0;i<height.size();i++){
            while(!st.empty() && st.top()<=height[i]){
                st.pop();
            }

            if(st.empty()){
                int volume = (width * start) - cnt;
                ans += volume;
                start = height[i];
                cnt = 0;
                width = 0;
            }else{
                width++;
                cnt += height[i];
            }

            st.push(height[i]);
        }

        if(st.size()==1){
            return ans;
        }

        while(!st.empty()) st.pop();
        int width2 = 0;
        int start2 = 0;
        cnt = 0;

        for(int i=0;i<=width;i++){
            while(!st.empty() && st.top()<=height[n-i-1]){
                st.pop();
            }

            if(st.empty()){
                int volume = (width2 * start2) - cnt;
                ans += volume;
                start2 = height[n-i-1];
                cnt = 0;
                width2 = 0;
            }else{
                width2++;
                cnt += height[n-i-1];
            }

            st.push(height[n-i-1]);

        }
        return ans;
    }
};