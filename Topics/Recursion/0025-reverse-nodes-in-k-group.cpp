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
        ListNode* prev=head;
        ListNode* dummy=new ListNode(-1,head);
        ListNode* tail=dummy;
        ListNode* curr=dummy;

        while(true){      
            for(int i=0;i<k;++i){
                curr=curr->next;
                if(!curr){
                    tail->next=prev;
                    return dummy->next;
                }
                
            }

            tail->next=curr;
            tail=prev;
            curr=curr->next;
            ListNode* temp1=curr;
            while(prev!=curr){
                ListNode* temp2=prev->next;
                prev->next=temp1;
                temp1=prev;
                prev=temp2;
            }
            curr=tail;
        }
    }
};
