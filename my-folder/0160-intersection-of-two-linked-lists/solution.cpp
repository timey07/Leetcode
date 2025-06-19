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
        if(headA==NULL || headB==NULL) return NULL;
        int c1=0;
        int c2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            c1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            c2++;
            temp2=temp2->next;
        }
        if(c1>=c2){
          c1=c1-c2;
          while(c1--) headA=headA->next;
          while(headA!=NULL && headB!=NULL){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
          }  
          return NULL;
        }
        else{
            c2=c2-c1;
            while(c2--) headB=headB->next;
            while(headB!=NULL && headA!=NULL){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
            }
            return NULL;
        }
    }
};
