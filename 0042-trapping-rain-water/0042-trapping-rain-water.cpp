class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int prev = 0;
        for(int i=0;i<n;i++){
            left[i] = max(height[i],prev);
            prev = left[i];
        }

        prev = 0;
        for(int i=n-1;i>=0;i--){
            right[i] = max(height[i],prev);
            prev = right[i];
        }

        for(int i=0;i<n;i++){
            int vol = min(right[i],left[i]) - height[i];
            ans+=vol;
        }
        return ans;

    }
};