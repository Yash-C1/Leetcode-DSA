class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int ans = INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[start]<=nums[mid]){
                // left part is sorted
                ans = min(ans,nums[start]);
                start = mid+1;
            }else{
                // right part is sorted
                ans = min(ans,nums[mid]);
                end = mid -1;

            }
        }
        return ans;
    }
};