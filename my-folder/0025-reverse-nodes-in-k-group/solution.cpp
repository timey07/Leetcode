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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail=head;
        ListNode* prevtail=new ListNode(-1);
        ListNode* prev=NULL;
        ListNode* mover=head;
        int sz=0;
        while(mover){
            sz++;
            mover=mover->next;
        }
        int sum=0;
        mover=head;
        while(mover){
            sum++;
           if(sum==k) head=mover;

            ListNode* temp=mover->next;
             
            if(sum%k==0){
                prevtail->next=mover;
                prevtail=tail;
                tail=temp;
                
            }
            mover->next=prev;
            prev=mover;
            mover=temp;

            if(sum%k==0 && sz-sum<k){
                    prevtail->next=temp;
                    break;
                }
        }
        return head;
    }
};
