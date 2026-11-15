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
        
        unordered_map<Node*,Node*> ump;

        Node* temp = head;

        while(temp){
            Node* node = new Node(temp->val);
            ump[temp] = node;

            temp = temp->next;
        }

        temp = head;

        Node* head2 = ump[head];

        while(temp){
            Node* node = ump[temp];
            node->next = ump[temp->next];
            node->random = ump[temp->random];
            temp = temp->next;
        }

        return head2;
    }
};
