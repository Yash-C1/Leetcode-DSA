class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;
        int curr = m+n-1;

        while(left>=0 && right>=0){
            if(nums2[right]>=nums1[left]){
                nums1[curr] = nums2[right];
                right--;
            }else{
                nums1[curr] = nums1[left];
                left--;
            }
            curr--;
        }

        while(right>=0){
            nums1[curr] = nums2[right];
            right--;
            curr--;
        }
    }
};