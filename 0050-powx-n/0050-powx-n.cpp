class Solution {
public:
    
    double myPow(double x, int n) {
        bool flag = false;
        bool neg = false;
        long m = (long) n;
        if(m<0){
            flag = true;
            m = abs(m);
        }
        if(x<0){
            if(m%2!=0) neg = true;
            x = abs(x);
        }

        double ans = 1;
        while(m!=0){
            if(m%2==0){
                x = x*x;
                m /= 2;
            }else{
                ans *= x;
                m--;
            }
        }
        if(flag) ans = 1/ans;

        return (neg ? -1*ans : ans);

    }
};

