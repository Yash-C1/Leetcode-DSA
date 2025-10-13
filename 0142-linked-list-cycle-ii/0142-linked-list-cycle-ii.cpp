/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Brute force solution
        unordered_map<ListNode*,int> mpp;
        ListNode* temp = head;
        if(temp==NULL || temp->next==NULL) return NULL;
        while(temp){
            if(mpp.find(temp)!=mpp.end()) return temp;
            else mpp[temp]++;
            temp = temp->next;
        }
        return NULL;





















        // ListNode* fast = head;
        // ListNode* slow = head;
        // while(fast!=NULL && fast->next!=NULL){
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if(slow==fast) {
        //         slow = head;
        //         while(true){
        //             if(slow==fast) return slow;
        //             slow = slow->next;
        //             fast = fast->next;
                    
        //         }
        //     }
        // }
        // return NULL;
    }
};