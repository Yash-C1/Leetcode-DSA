class Solution {
private:
    void mark_nse(vector<int>& arr, vector<int>& nse){
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = arr.size();
            else nse[i] = st.top();
            st.push(i);
        }
    }

    void mark_psee(vector<int>& arr, vector<int>& psee){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) psee[i] = -1;
            else psee[i] = st.top();
            st.push(i);
        }
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = (int) (1e9 + 7);
        int ans = 0;
        vector<int> nse(arr.size());
        vector<int> psee(arr.size());
        mark_nse(arr,nse);
        mark_psee(arr,psee);

        for(int i=0;i<arr.size();i++){
            int left = nse[i]-i;
            int right = i-psee[i];
            long long val = left*right*1LL;
            int contribution = (arr[i]*val) % mod;
            ans = (ans + contribution) % mod;
        }
        return ans;
    }
};