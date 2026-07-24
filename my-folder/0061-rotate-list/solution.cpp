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
        
        int len=0;
        ListNode* temp=head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0) return head;
        ListNode* slow=head;
        ListNode* prev=slow;
        temp=head;
        while(k--) temp=temp->next;
        while(temp){
            prev=slow;
            slow=slow->next;
            temp=temp->next;
        }
        prev->next=NULL;
        temp=slow;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return slow;
    }
};
