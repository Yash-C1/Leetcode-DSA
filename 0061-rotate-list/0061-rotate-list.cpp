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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        if(!head || !head->next) return head;
        ListNode* traverse = head;
        while(traverse){
            size++;
            traverse = traverse->next;
        }
        k = k%size;
        if(k==0) return head;
        int counter = size-k-1;
        traverse = head;
        while(counter>0){
            counter--;
            traverse = traverse->next;
        }

        ListNode* new_head = traverse->next;
        traverse->next = NULL;
        ListNode* temp = new_head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next = head;
        return new_head;
    }
};