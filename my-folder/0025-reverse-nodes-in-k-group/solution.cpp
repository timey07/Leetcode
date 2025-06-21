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
void reversell(ListNode* &start) {
    ListNode* prev=NULL;
    ListNode* curr=start;
    ListNode* ne=start->next;
    while(curr!=NULL){
        curr->next=prev;
        prev=curr;
        curr=ne;
        if(ne) ne=ne->next;
    }
}


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* temp=head;
        ListNode* kth=head;
        ListNode* temp3=head;
        int t=k-1;
        while(kth!=NULL){
            t--;
            kth=kth->next;
            if(kth==NULL){
                temp3->next=temp;
                break;
            }
            if(t==0){
                t=k-1;
                ListNode* temp2=kth->next;
                kth->next=NULL;
                reversell(temp);
                if(temp3==head){
                    head=kth;
                    temp=temp2;
                    kth=temp2;
                }
                else{
                    temp3->next=kth;
                    temp3=temp;
                    temp=temp2;
                    kth=temp2;
                }
            }
        }
        return head;
    }
};
