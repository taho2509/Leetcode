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
    bool isPalindrome(ListNode* head) {
        vector<int> pals;
        while(head != nullptr) {
            pals.push_back(head->val);
            head = head->next;
        }
        
        int n = pals.size();
        
        for(int i = 0; i < n/2; i++) {
            if(pals[i] != pals[n - i - 1]) return false;
        }
        
        return true;
    }
};