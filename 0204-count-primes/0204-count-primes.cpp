class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        int arr[n+1];
        for(long i=2;i<n;i++){
            arr[i] = 1;
        }
        for(long i = 2;i<n;i++){
            if(arr[i]==1){
                ans++;
                for(long j = i*i; j<n;j+=i){
                    arr[j] = 0;
                }
            }
        }
        return ans;
    }
};