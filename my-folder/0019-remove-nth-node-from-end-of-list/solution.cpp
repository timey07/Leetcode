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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev;
        while(fast!=NULL){
            while(n){
                fast=fast->next;
                n--;
            }
            if(fast==NULL) break;
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(slow==head) return head->next;
        prev->next=slow->next;
        slow->next=NULL;
        delete(slow);
        return head;
    }
};
