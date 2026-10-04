class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        int n = hand.size();
        vector<bool> visited(n, false);

        int a = 0;

        while (a < n) {

            while (a < n && visited[a])
                a++;

            if (a == n)
                break;

            visited[a] = true;

            int prev = hand[a];
            int count = 1;

            int b = a + 1;

            while (count < groupSize) {
                while (b < n && visited[b])
                    b++;

                if (b == n)
                    return false;

                if (hand[b] == prev + 1) {
                    visited[b] = true;
                    prev = hand[b];
                    count++;
                }
                else {
                    if (hand[b] == prev) {
                        b++;
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};



//  1 2 3 6 2 3 4 7 8
//  1 2 2 3 3 4 6 7 8