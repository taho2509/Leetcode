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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * curr = head, *first = head, *second = head;
        int n = 0;
        while(curr != nullptr) {
            curr = curr->next;
            n++;
        }
        
        int p = n - k;
        k--;
        
        while(k > 0) {
            first = first->next;
            k--;
        }
        
        while(p > 0) {
            second = second->next;
            p--;
        }
        
        int t = first->val;
        first->val = second->val;
        second->val = t;       
        
        
        return head;
    }
};