// class Solution {
// private:
//     bool check(vector<int>& freqS, vector<int>& freqT) {
//         for (int i = 0; i < 128; i++) {
//             if (freqT[i] > freqS[i]) return false;
//         }
//         return true;
//     }

// public:
//     string minWindow(string s, string t) {
//         vector<int> freqS(128, 0);
//         vector<int> freqT(128, 0);

//         for (char c : t) freqT[c]++;

//         int l = 0;
//         int l_idx = -1;
//         int ansLen = INT_MAX;

//         for (int r = 0; r < s.size(); r++) {
//             freqS[s[r]]++;

//             // shrink while window is valid
//             while (check(freqS, freqT)) {
//                 if (r - l + 1 < ansLen) {
//                     ansLen = r - l + 1;
//                     l_idx = l;
//                 }

//                 freqS[s[l]]--;
//                 l++;           
//             }
//         }

//         return l_idx == -1 ? "" : s.substr(l_idx, ansLen);
//     }
// };



class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        for (char c : t) freq[c]++;
        int r = 0;
        int l = 0;
        int l_idx = -1;
        int ansLen = INT_MAX;
        int cnt = 0;

        while(r<s.size()) {
            if(freq[s[r]]>0) cnt++;
            freq[s[r]]--;

            while (cnt==t.size()) {
                if (r - l + 1 < ansLen) {
                    ansLen = r - l + 1;
                    l_idx = l;
                }

                freq[s[l]]++;
                if(freq[s[l]]>0) cnt--;
                l++;           
            }
            r++;
        }

        return l_idx == -1 ? "" : s.substr(l_idx, ansLen);
    }
};
