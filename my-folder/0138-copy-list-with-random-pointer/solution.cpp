/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL){
            Node* copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }

        temp=head;
        while(temp!=NULL){

            if(temp->random)temp->next->random=temp->random->next;
            else temp->next->random=temp->random;
            temp=temp->next->next;
        }

        Node* dummy=new Node(-1);
        Node* res=dummy;
        temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;

    }
};
