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
        unordered_map<ListNode*,int>mpp;
        ListNode* traverse = headA;
        while(traverse){
            mpp[traverse]++;
            traverse = traverse->next;
        }
        traverse = headB;
        while(traverse){
            if(mpp.find(traverse)!=mpp.end()){
                return traverse;
            }
            traverse = traverse->next;
        }
        return NULL;
    }
};