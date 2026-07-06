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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp=NULL;
        while(slow){
            ListNode* nextt=slow->next;
            slow->next=temp;
            temp=slow;
            slow=nextt;
        }
        slow=temp;
        fast=head;
        while(slow){
            if(slow->val != fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
