class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for(int i=0;i<numRows;i++){
            vector<int> temp;
            long long ans = 1;
            temp.push_back(1);
            for(int j=0;j<i;j++){
                ans = ans*(i-j);
                ans /= (j+1);
                temp.push_back((int)ans);
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};