class Solution {
public:
    string reverseWords(string s) {
        // string ans="";
        // string temp="";
        // for(int i=0;i<s.size();i++){
            
        //     if(s[i]==' '){
        //         if(ans!="" && temp!="") ans = temp+ " "+ans;
        //         else ans = temp+ans;
        //         temp="";
        //     }else{
        //         temp+=s[i];
        //     }

        // }
        // if(ans!="" && temp!="") ans = temp+ " "+ans;
        // else ans = temp+ans;
        // return ans;

        // string ans = "";
        // string temp = "";
        // for(int i = 0;i<s.size();i++){
        //     if(s[i]==' '){
        //         if(ans!="" && temp !="") ans = temp+" "+ans;
        //         else{
        //             ans = temp+ans;
        //         }
        //         temp="";

        //     }else{
        //         temp+=s[i];
        //     }
        // }
        // if(ans!="" && temp!="") ans = temp+ " "+ans;
        // else ans = temp+ans;
        // return ans;










        string ans = "";
        string temp = "";
        int space_counter = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') {
                space_counter=0;
                temp+=s[i];
            }
            if(s[i]==' ' && temp!=""){
                space_counter++;
                if(space_counter==1) ans = temp + " " + ans;
                // else if(space_counter==1 && ans=="") ans = temp + ans;
                temp = "";
            }
            if(i==s.size()-1 && s[i]!=' ') ans = temp+ " "+ ans;
        }
        if(ans!="") ans.erase(ans.size()-1);
        return ans;










    }
};