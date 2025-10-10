class Solution {
public:
    int myAtoi(string s) {
        // int ans = 0;
        // int i = 0;
        // int n = s.size();
        // bool neg = false;

        // // Skip leading whitespaces
        // while (i < n && s[i] == ' ') {
        //     i++;
        // }

        // // Check for sign
        // if (i < n && s[i] == '-') {
        //     neg = true;
        //     i++;
        // } else if (i < n && s[i] == '+') {
        //     i++;
        // }

        // // Process the digits
        // while (i < n && s[i] >= '0' && s[i] <= '9') {
        //     int digit = s[i] - '0';

        //     // Check for overflow
        //     if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
        //         return neg ? INT_MIN : INT_MAX;
        //     }

        //     ans = ans * 10 + digit;
        //     i++;
        // }

        // return neg ? -ans : ans;


        int ans = 0;
        bool sign_checked = false;
        bool negative = false;
        bool first_digit_checked = false;
        for(int i=0;i<s.size();i++){
            if(!sign_checked && !first_digit_checked && s[i]==' ') continue;
            if(!sign_checked && !first_digit_checked && s[i]=='+') {
                sign_checked = true;
                continue;
            }
            if(!sign_checked && !first_digit_checked && s[i]=='-') {
                negative = true;
                sign_checked = true;
                continue;
            }
            int digit = s[i]-'0';
            if(digit>10 || digit<0) break;
            else if(digit>=0 && digit<10){
                first_digit_checked = true;
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                    return negative ? INT_MIN : INT_MAX;
                }
                ans*=10;
                ans+=digit;
            }
        }

        return negative ? -ans:ans;






    







        
    }
};