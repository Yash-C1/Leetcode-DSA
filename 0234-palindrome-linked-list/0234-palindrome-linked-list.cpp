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
    bool isPalindrome(ListNode* head) {
        
        int counter = 0;
        if(!head || !head->next) return true;
        ListNode* temp = head;
        while(temp){
            counter++;
            temp = temp->next;
        }

        int mid_point = counter/2;
        counter=0;
        ListNode* mover1 = head;
        ListNode* mover2 = head;
        while(counter!=mid_point){
            counter++;
            mover2 = mover2->next;
        }

        ListNode* prev = NULL;
        while(mover2){
            ListNode* temp = mover2->next;
            mover2->next = prev;
            prev = mover2;
            mover2 = temp;
        }



        while(prev){
            if(mover1->val!=prev->val) return false;
            mover1 = mover1->next;
            prev = prev->next;
        }
        return true;















        // if (!head || !head->next) return true; 

      
        // ListNode* slow = head;
        // ListNode* fast = head;
        // while (fast && fast->next) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }

       
        // ListNode* prev = NULL;
        // while (slow) {
        //     ListNode* nextNode = slow->next;
        //     slow->next = prev;
        //     prev = slow;
        //     slow = nextNode;
        // }

       
        // ListNode* left = head;  
        // ListNode* right = prev;  
        // while (right) {
        //     if (left->val != right->val) return false;
        //     left = left->next;
        //     right = right->next;
        // }

        // return true;
    }
};