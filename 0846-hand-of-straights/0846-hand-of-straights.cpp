// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         if (hand.size()%groupSize != 0) return false;
//         sort(hand.begin(),hand.end());
//         vector<int> visited(hand.size(), 0);
//         int a = 0;
//         int b = 0;
//         int prev = hand[0];
//         while (b < hand.length()) {
//             visited[a] = 1;
//             int target = hand[a] + groupSize - 1;
//             while (true){
//                 if(b >= hand.length() || hand[b]>target) return false;
//                 if (hand[b]==target) break; 
//                 b++;
//                 if (hand[b]=prev+1) visited[b] = 1;
//                 prev = hand[b];
//             }

//         }
        

//     }
// };


// // 1 2 2 3 3 4 6 7 8

// // 1 1 0 0 0 0 0 0 0


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

            // Find first unvisited card.
            while (a < n && visited[a])
                a++;

            if (a == n)
                break;

            visited[a] = true;

            int prev = hand[a];
            int count = 1;

            int b = a + 1;

            while (count < groupSize) {

                // Skip cards already used.
                while (b < n && visited[b])
                    b++;

                if (b == n)
                    return false;

                // If this card is the next consecutive value,
                // use it.
                if (hand[b] == prev + 1) {
                    visited[b] = true;
                    prev = hand[b];
                    count++;
                }
                else {
                    // If it's a duplicate of the previous card,
                    // skip it and keep searching.
                    if (hand[b] == prev) {
                        b++;
                    }
                    else {
                        // Since the array is sorted, if we're
                        // already past prev + 1, that value doesn't exist.
                        return false;
                    }
                }
            }
        }

        return true;
    }
};



