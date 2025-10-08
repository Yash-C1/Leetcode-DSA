class Solution {
public:
    bool check_possiblity(vector<int>& nums, int k, int mid){
        int counter = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                counter++;
                sum = nums[i];
            }else sum+=nums[i];
        }
        return counter <= k;
    } 
    
    int splitArray(vector<int>& nums, int k) {
        int start = INT_MIN;
        int end = 0;
        for(int i=0;i<nums.size();i++){
            end+=nums[i];
            start = max(start,nums[i]);
        }

        while(start<=end){
            int mid = start + (end-start)/2;
            bool possible = check_possiblity(nums, k, mid);
            if(possible){
                end = mid -1;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};