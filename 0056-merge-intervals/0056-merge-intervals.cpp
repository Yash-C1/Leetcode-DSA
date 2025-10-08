class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int j = 1;
        if(intervals.size()==1) return intervals;
        while(j<intervals.size()){
            if(intervals[j][0]<=end) end = max(end,intervals[j][1]);
            else{
                ans.push_back({start,end});
                start = intervals[j][0];
                end = intervals[j][1];
            }
            j++;
        }
        ans.push_back({start,end});
        return ans;
    }
};