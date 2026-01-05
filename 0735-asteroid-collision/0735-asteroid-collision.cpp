class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) ans.push_back(asteroids[i]);
            else{
                int temp = abs(asteroids[i]);
                while(ans.size() !=0  && temp > ans.back() && ans.back()>0){
                    ans.pop_back();
                }

                if(ans.size()!=0 && ans.back()==temp) ans.pop_back();
                else if(ans.size() == 0 || ans.back() < 0) ans.push_back(asteroids[i]);
            }
        }
        return ans;
        
    }
};