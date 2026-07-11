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
        if (!head) return nullptr;

    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
        Node* copy = new Node(curr->val);
        curr->next = copy;
        copy->next = next;
        curr = next;
    }

    curr = head;

    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    curr = head;
    Node* dummy = new Node(0);
    Node* copyTail = dummy;

    while (curr) {
        Node* next = curr->next->next;
        Node* copy = curr->next;

        copyTail->next = copy;
        copyTail = copy;

        curr->next = next;
        curr = next;
    }

    return dummy->next;
    }
};
