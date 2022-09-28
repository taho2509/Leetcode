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
        ListNode* start = new ListNode(0, head);
        
        while(n > 0) {
            head = head->next;
            n--;
        }
        
        ListNode* curr = start;
        while(head != nullptr) {
            head = head->next;
            curr = curr->next;
        }
        
        curr->next = curr->next->next;
        
        return start->next;
    }
};