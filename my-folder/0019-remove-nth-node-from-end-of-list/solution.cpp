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
        int total=0;
        ListNode* temp=head;
        while(temp!=NULL){
            total++;
            temp=temp->next;
        }
        if(total==n){
            ListNode* del=head;
            head=head->next;
            delete(del);
            return head;
        }
        n=total-n;
        n--;
        temp=head;
        while(n>0){
            temp=temp->next;
            n--;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        delete(del);
        return head;
    }
};
