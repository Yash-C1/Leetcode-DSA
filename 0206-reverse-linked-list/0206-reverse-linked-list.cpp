/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* helper(ListNode* prev, ListNode* mover){
        if(mover==NULL) return prev;
        ListNode* temp = mover->next;
        mover->next = prev;
        prev = mover;
        mover = temp;
        return helper(prev,mover);

    }
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL || head->next==NULL) return head;
        // ListNode* mover = head;
        // ListNode* prev = NULL;
        // while(mover){
        //     ListNode* temp = mover->next;
        //     mover->next = prev;
        //     prev = mover;
        //     mover = temp;
        // }
        // return prev;

        if(head==NULL || head->next==NULL) return head;
        ListNode* mover = head;
        ListNode* prev = NULL;
        return helper(prev,mover);

    }
};