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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> copy;
        
        while(head!=nullptr) {
            copy.push_back(head->val);
            head = head->next;
        }
        int n = copy.size();
        
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        --left, --right;
        int i = 0;
        while(i < left) {
            current->next = new ListNode(copy[i++]);
            current = current->next;
        }
        
        i = right;
        while(i >= left) {
            current->next = new ListNode(copy[i--]);
            current = current->next;
        }
        
        i = right + 1;
        while(i < n) {
            current->next = new ListNode(copy[i++]);
            current = current->next;
        }
        return dummy->next;
    }
};