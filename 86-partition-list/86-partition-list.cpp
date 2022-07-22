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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        bool found = false;
        ListNode* first = new ListNode(0, head);
        ListNode* curr = head;
        head = first;

        while(!found && curr != nullptr) {
            if(!found && curr->val >= x) {
                found = true;
                first = curr;
                break;
            }
            curr = curr->next;
        }
        
        if(!found || curr->next == nullptr) return head->next;
        ListNode *dummy = new ListNode();
        ListNode *saga = dummy;
        ListNode *next = curr->next;
        
        while(next != nullptr) {
            if(next->val < x) {
                // extracting next from original list
                curr->next = next->next;
                
                // adding next to new list
                saga->next = next;
                saga = saga->next;
                saga->next = nullptr;
            } else {
                curr = curr->next;
            }
            next = curr->next;
        }
        
        if(dummy->next == nullptr) return head->next;
        
        curr = head;
        while(curr->next != first && curr->next != nullptr) {
            curr = curr->next;
        }
        
        curr->next = dummy->next;
        saga->next = first;
        
        return head->next;
    }
};