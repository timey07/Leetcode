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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* even=head;
        ListNode* odd=head->next;
        ListNode* ini=odd;
        ListNode* in=even;
        int sw=0;
        head=head->next->next;
        while(head!=NULL){
            if(sw==0){
                sw=1;
                even->next=head;
                even=even->next;
            }
            else{
                sw=0;
                odd->next=head;
                odd=odd->next;
            }
            head=head->next;
        }
        even->next=ini;
        odd->next=nullptr;
        return in;
    }
};
