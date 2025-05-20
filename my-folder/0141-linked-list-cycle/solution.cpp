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
    bool hasCycle(ListNode *head) {
        bool ans=0;
        if(head==nullptr) return false;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow && fast){
            if(slow==fast) return true;
            slow=slow->next;
            if(fast->next==nullptr) return false;
            fast=fast->next->next;
        }
        return false;
    }
};
