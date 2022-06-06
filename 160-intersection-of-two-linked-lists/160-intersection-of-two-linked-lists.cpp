/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        
        while(currentA != currentB) {
            currentA = currentA == NULL ? headB : currentA->next;
            currentB = currentB == NULL ? headA : currentB->next;
        }
        
        return currentA;
    }
};