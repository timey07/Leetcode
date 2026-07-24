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
        ListNode* a=headA;
        ListNode* b=headB;

        while(a!=b){
            if(a) a=a->next;
            else a=headB;

            if(b) b=b->next;
            else b=headA;
        }
        // if(!a && !b) return NULL;
        // if(!a){
        //     a=headB;
        //     while(a){
        //         if(a==b) return a;
        //         a=a->next;
        //         b=b->next;
        //         if(b==NULL) b=headA;
        //     }
        // }
        // else{
        //     b=headA;
        //     while(b){
        //         if(a==b) return a;
        //         a=a->next;
        //         b=b->next;
        //         if(a==NULL) a=headB;
        //     }
        // }
        return a;
    }
};
