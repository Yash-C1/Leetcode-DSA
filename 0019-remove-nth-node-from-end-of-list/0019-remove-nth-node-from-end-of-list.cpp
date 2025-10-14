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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        int counter = 0;
        while(fast){
            counter++;
            if(counter>n){
                prev = slow;
                slow = slow->next;
            }
            fast = fast->next;
        }
        if (prev == NULL) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};