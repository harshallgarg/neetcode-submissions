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

    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while(head){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }


    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* l1 = head;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                break;
            }
        }

        ListNode* l2 = reverseLinkedList(slow);

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        bool flag = 0;

        while(l1 and l2){
            if(flag==0){
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
                flag = 1;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
                flag = 0;
            }
        }

        return;
    }
};
