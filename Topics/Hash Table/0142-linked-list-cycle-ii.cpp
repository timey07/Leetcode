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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool check=0;
        while(slow && fast && head){
            if(fast->next==NULL) break;
            slow=slow->next;
            if(!check) fast=fast->next->next;
            else fast=fast->next;
            if(slow==fast && check) return slow;
            if(slow==fast){
                check=1;
                slow=head;
                if(slow==fast) return slow;
            }
        }
        return NULL;
    }
};
