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
        // unordered_map<ListNode*,int> mpp;
        // ListNode* temp = head;
        // if(temp==NULL || temp->next==NULL) return NULL;
        // while(temp){
        //     if(mpp.find(temp)!=mpp.end()) return temp;
        //     else mpp[temp]++;
        //     temp = temp->next;
        // }
        // return NULL;

        
        // Optimal solution
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                slow = head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};