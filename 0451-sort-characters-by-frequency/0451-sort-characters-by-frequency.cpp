class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> v;
        for(int i=0;i<=122;i++) v.push_back({i,0});
        for(int i=0;i<s.size();i++){
            int index = s[i];
            v[index].second++;
        }

        sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) {
            return a.second > b.second; 
        });

        string ans = "";
        int i=0;
        while(true){
            pair<int,int> p = v[i];
            if(p.second==0) break;
            for(int j=0;j<p.second;j++){
                ans+=p.first;
            }
            i++;
        }

        return ans;


    }
};