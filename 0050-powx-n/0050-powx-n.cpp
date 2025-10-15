class Solution {
public:
    void helper(double &x, double &ans, long n){
        if(n<=0) return;
        if(n%2==0){
            x*=x;
            n/=2;
        }else{
            ans*=x;
            n--;
        }
        helper(x,ans,n);
    }
    double myPow(double x, int n) {
        long abs_n = labs(n);
        double ans = 1;
        helper(x,ans,abs_n);

        // while(abs_n>0){
        //     if(abs_n%2==0){
        //         x*=x;
        //         abs_n/=2;
        //     }else{
        //         ans*=x;
        //         abs_n--;
        //     }
        // }
        
        ans = (n>0) ? ans : (1/ans);
        return ans;
    }
};

