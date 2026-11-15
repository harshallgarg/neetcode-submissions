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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        temp->next = head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = dummy;

       while(n--){
        fast = fast->next;
       }

       while(fast){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
       }

        prev->next = prev->next->next;

       return temp->next;
    }
};
