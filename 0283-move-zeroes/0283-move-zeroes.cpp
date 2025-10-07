class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = -1;
        int i = 0;
        while(i<nums.size()){
            if(nums[i]==0){
                zero_index = i;
                break;
            }
            i++;
        }

        if(zero_index==-1) return;
        if(nums.size()==1) return;

        int j = zero_index+1;
        while(j<nums.size()){
            if(nums[j]!=0){
                swap(nums[j],nums[zero_index]);
                zero_index++;
            }
            j++;
        }
    }
};