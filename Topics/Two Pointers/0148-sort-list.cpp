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
    ListNode* fm(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* ans= new ListNode(-1);
        ListNode* temp=ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1) temp->next=l1;
        else temp->next=l2;
        return ans->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* mid= fm(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        
        ListNode* left=sortList(head);
        right= sortList(right);
        return merge(left,right);
    }
};
