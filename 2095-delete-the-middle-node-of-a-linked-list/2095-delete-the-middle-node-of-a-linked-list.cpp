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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr) {
            ++n;
            curr = curr->next;
        }
        
        n /= 2;
        
        ListNode* dummy = new ListNode(0, head);
        curr = dummy;
        while(n > 0) {
            --n;
            head = head->next;
            curr = curr->next;
        }
        
        curr->next = head->next;
        
        return dummy->next;
    }
};