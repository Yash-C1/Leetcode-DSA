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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Brute force method
        // unordered_map<ListNode*,int>mpp;
        // ListNode* traverse = headA;
        // while(traverse){
        //     mpp[traverse]++;
        //     traverse = traverse->next;
        // }
        // traverse = headB;
        // while(traverse){
        //     if(mpp.find(traverse)!=mpp.end()){
        //         return traverse;
        //     }
        //     traverse = traverse->next;
        // }
        // return NULL;



        // Optimal approach
        int length1 = 0;
        int length2 = 0;
        ListNode* traverse = headA;
        while(traverse){
            length1++;
            traverse = traverse->next;
        }

        traverse = headB;
        while(traverse){
            length2++;
            traverse = traverse->next;
        }

        ListNode* temp = NULL;

        if(length1>length2){
            traverse = headA;
            while(length2<length1) {
                traverse = traverse->next;
                length2++;
            }
            temp = headB;
        }else{
            traverse = headB;
            while(length1<length2) {
                traverse = traverse->next;
                length1++;
            }
            temp = headA;
        }

        while(traverse){
            if(traverse==temp) return traverse;
            traverse = traverse->next;
            temp = temp->next;
        }

        return NULL;
    }
};