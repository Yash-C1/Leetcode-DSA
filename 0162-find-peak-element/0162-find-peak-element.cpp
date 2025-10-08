class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1;
        int end = nums.size()-2;
  
        
        if(nums.size()==1) return 0;
        if(nums.size()==2){
            if(nums[0]>nums[1]) return 0;
            else if(nums[0]<nums[1]) return 1;
            else return -1;
        }
        if(nums[0]>nums[1]) return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid-1]>nums[mid]) end = mid-1;
            else start = mid+1;
            
        }
        return -1;
    }
};