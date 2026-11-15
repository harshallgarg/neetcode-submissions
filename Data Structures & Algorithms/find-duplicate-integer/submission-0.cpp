class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int slow = v[0];
        int fast = v[0];

        slow = v[slow];
        fast = v[v[fast]];

        while(slow!=fast){
            slow = v[slow];
            fast = v[v[fast]];
        }

        int head = v[0];

        while(head!=slow){
            head = v[head];
            slow = v[slow];
        }

        return head;
    }
};
