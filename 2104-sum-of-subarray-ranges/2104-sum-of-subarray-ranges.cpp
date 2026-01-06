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

    void mark_nge(vector<int>& arr, vector<int>& nse){
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = arr.size();
            else nse[i] = st.top();
            st.push(i);
        }
    }

    void mark_pgee(vector<int>& arr, vector<int>& psee){
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()) psee[i] = -1;
            else psee[i] = st.top();
            st.push(i);
        }
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> nse(n);
        vector<int> psee(n);
        vector<int> nge(n);
        vector<int> pgee(n);

        mark_nse(nums,nse);
        mark_psee(nums,psee);
        mark_nge(nums,nge);
        mark_pgee(nums,pgee);


        for(int i=0;i<n;i++){
            long long freq1 = (nse[i]-i)*(i-psee[i]);
            long long freq2 = (nge[i]-i)*(i-pgee[i]);
            ans += (freq2-freq1)*nums[i]; 
        }
        return ans;
    }
};