class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int a = -1;
        int b = -1;
        int c = -1;

        for(int i=0;i<s.size();i++){
            if(a==-1 || b==-1 || c==-1){
                if(s[i]=='a') a = i;
                if(s[i]=='b') b = i;
                if(s[i]=='c') c = i;
                if(a!=-1 && b!=-1 && c!=-1) cnt+=1+min({a, b, c});
            }else{
                cnt += 1;
                if(s[i]=='a') {
                    cnt += min(b,c);
                    a = i;
                }
                if(s[i]=='b') {
                    cnt += min(a,c);
                    b = i;
                }
                if(s[i]=='c') {
                    cnt += min(a,b);
                    c = i;
                }
            }
        }


        return cnt;
    }
};