class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end){
        int left = start;
        int right = mid+1;
        vector<int> temp;
        while(left<=mid && right<=end){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }else{
                temp.push_back(nums[left]);
                left++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=end){
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
    }

    void count_pairs(vector<int> &nums, int start, int mid, int end, int &ans){
        int j = mid+1;
        for(int i=start;i<=mid;i++){
            while (j <= end && (long long)nums[i] > 2LL * nums[j]){
                j++;
            }
            ans+=(j-(mid+1));
        }
    }

    void mergeSort(vector<int>& nums, int start, int end, int &ans){
        if(start==end) return;
        int mid = (start+end)/2;
        mergeSort(nums,start,mid,ans);
        mergeSort(nums,mid+1,end,ans);
        count_pairs(nums,start,mid,end,ans);
        merge(nums, start, mid, end);
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};