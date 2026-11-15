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

        if(head==NULL)
        return NULL;

        Node* temp = head;
        Node* nextNode = NULL;

        while(temp){
            Node* newNode = new Node(temp->val);
            nextNode = temp->next;
            temp->next = newNode;
            newNode->next = nextNode;
            temp = nextNode;
        }

        temp = head;
        Node* head2 = head->next;

        Node* temp2 = NULL;

        // connect random nodes
        while(temp){
            Node* copyNode = temp->next;

            if(temp->random)
            copyNode->random = temp->random->next;
            else
            copyNode->random = NULL;

            temp = copyNode->next;
        }

        // reforming both linkedList's sequence

        temp = head;

        while(temp){
            Node* copyNode = temp->next;
            temp->next = copyNode->next;
            copyNode->next = temp->next ? temp->next->next : NULL;
            temp = temp->next;
        }

        return head2;  
    }
};
