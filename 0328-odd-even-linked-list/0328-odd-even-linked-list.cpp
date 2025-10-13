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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        while(odd && even){
            odd->next = odd->next->next;
            if(odd->next) odd = odd->next;
            if(even->next) even->next = even->next->next;
            even = even->next;
        } 

        odd->next = even_head;
        return head;
















        // ListNode* odd = head;
        // ListNode* even = head->next;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     ListNode* temp2 = temp->next;
        //     temp->next = temp->next->next;
        //     temp = temp2->next;
        // }

        // ListNode* trav = odd;
        // while(trav->next!=NULL){
        //     trav = trav->next;
        // }
        // trav->next = even;

        // return odd;

        // if (!head || !head->next) return head;  // Handle edge cases
    
        // ListNode* odd = head;
        // ListNode* even = head->next;
        // ListNode* evenHead = even;  // Store the start of even list

        // while (even && even->next) {  // Ensure even and even->next are not NULL
        //     odd->next = even->next;
        //     odd = odd->next;
        //     even->next = odd->next;
        //     even = even->next;
        // }

        // odd->next = evenHead;  // Connect odd and even lists

        // return head;
    }
};