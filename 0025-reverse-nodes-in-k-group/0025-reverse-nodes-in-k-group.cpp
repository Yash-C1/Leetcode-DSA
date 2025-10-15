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
    ListNode* reverseLL(ListNode *head){
        ListNode* temp = head;  

        ListNode* prev = NULL;  

        while(temp != NULL){  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        
        return prev;  
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int size = 0;
        ListNode* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        temp = head;

        while (size >= k) {
            // Find the end of this k-group
            ListNode* start = temp;
            for (int i = 1; i < k; i++) temp = temp->next;
            ListNode* nextGroupStart = temp->next;
            temp->next = nullptr; // Detach

            // Reverse this group
            ListNode* newHead = reverseLL(start);

            // Connect previous group to this reversed one
            prevGroupEnd->next = newHead;
            start->next = nextGroupStart;

            // Move pointers forward
            prevGroupEnd = start;
            temp = nextGroupStart;
            size -= k;
        }

        return dummy.next;
    }
};