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
    bool hasCycle(ListNode *head) {

        // Brute force solution
        // unordered_map<ListNode*, int> mpp;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     if(mpp.find(temp)!=mpp.end()) return true;
        //     mpp[temp]++;
        //     temp = temp->next;
        // }
        // return false;



        // Optimal solution
        if(head==NULL || head->next==NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }
        return false;
        
    }
};