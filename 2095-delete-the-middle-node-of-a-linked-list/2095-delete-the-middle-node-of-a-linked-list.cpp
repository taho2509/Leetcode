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
        if(head->next == nullptr) return nullptr;
        
        ListNode* slow = head, *fast = head, *last = head;
        
        while(fast != nullptr) {
            fast = fast->next;
            if(fast!= nullptr) fast = fast->next;
            else break;
            last = slow;
            slow = slow->next;
        }
        
        last->next = slow->next;
        
        return head;
    }
};