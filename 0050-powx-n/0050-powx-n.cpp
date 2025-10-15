class Solution {
public:
    double myPow(double x, int n) {
        long abs_n = labs(n);
        double ans = 1;
        while(abs_n>0){
            if(abs_n%2==0){
                x*=x;
                abs_n/=2;
            }else{
                ans*=x;
                abs_n--;
            }
        }
        
        ans = (n>0) ? ans : (1/ans);
        return ans;
    }
};

