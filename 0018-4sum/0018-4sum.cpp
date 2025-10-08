class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return {};
        for(int i=0;i<nums.size()-3;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j > i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum>target){
                        l--;
                    }else if(sum<target){
                        k++;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l--;
                        k++;
                        while(k < l && nums[l]==nums[l+1]) l--;
                        while(k < l && nums[k]==nums[k-1]) k++;
                    }
                }
            }
        }
        
        return ans;
        // vector<vector<int>> ans;
        // sort(nums.begin(),nums.end());
        // if(nums.size()<4) return {};
        // for(int i = 0; i< nums.size()-3;i++){
        //     if(i!=0 && nums[i]==nums[i-1]) continue;
        //     for(int j = i+1; j<nums.size()-2;j++){
        //         if(nums.size()>1 && j!=i+1 && nums[j]==nums[j-1]) continue;
                
        //         int a = j+1;
        //         int b = nums.size()-1;
        //         while(a<b){
        //             long long sum = nums[i]+nums[j];
        //             sum+=nums[a];
        //             sum+=nums[b];
        //             if(sum==target){
        //                 vector<int> temp = {nums[i],nums[j],nums[a],nums[b]};
        //                 ans.push_back(temp);
        //                 a++;
        //                 b--;
        //                 while(a<b && nums[a]==nums[a-1]) a++;
        //                 while(a<b && nums[b]==nums[b+1]) b--;
        //             }else if(sum > target){
        //                 b--;
        //             }else{
        //                 a++;
        //             }
        //         }
        //     }
        // }
        // return ans;
    }
};