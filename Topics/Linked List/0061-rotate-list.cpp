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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        k=(k%size);
        if(k==0) return head;
        k=size-k;
        temp=head;
        ListNode* previous;
        while(k--){
            previous=temp;
            temp=temp->next;
        }
        previous->next=NULL;
        ListNode* newhead=temp;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=head;
        head=newhead;
        return head;
    }
};
