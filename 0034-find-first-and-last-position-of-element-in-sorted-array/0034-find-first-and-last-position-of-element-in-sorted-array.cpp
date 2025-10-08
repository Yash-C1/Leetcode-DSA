class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int first = -1;
        int last = -1;

        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                first = mid;
                end = mid-1;
            }else if(nums[mid]>target){
                end = mid -1;
            }else {
                start = mid+1;
            }
        }

        if(first==-1) return {-1,-1};

        start = 0;
        end = nums.size()-1;

        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target){
                last = mid;
                start = mid+1;
            }else if(nums[mid]>target){
                end = mid -1;
            }else {
                start = mid+1;
            }
        }


        return {first,last};
    }
};