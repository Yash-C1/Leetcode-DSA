class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z_count = 0;
        int o_count = 0;
        int t_count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) z_count++;
            if(nums[i]==1) o_count++;
            if(nums[i]==2) t_count++;
        }

        int i=0;
        while(z_count>0){
            nums[i]=0;
            i++;
            z_count--;
        }

        while(o_count>0){
            nums[i]=1;
            i++;
            o_count--;
        }

        while(t_count>0){
            nums[i]=2;
            i++;
            t_count--;
        }
    }
};