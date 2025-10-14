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
    ListNode* get_mid(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next; 
        }

        if (left != NULL) {
            temp->next = left;
        } else {
            temp->next = right;
        }

        return dummyNode->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle = get_mid(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left,right);

    }
};