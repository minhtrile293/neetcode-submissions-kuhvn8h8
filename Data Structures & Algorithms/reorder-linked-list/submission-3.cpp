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
    void reorderList(ListNode* head) {
        
        // 1. Split into 2 list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 1 2 3
        // 6 5 4
        // 2. Reverse 
        ListNode* second = nullptr;
        ListNode* middle = slow->next;
        slow->next = nullptr;
        slow = middle;
        
        while(slow){
            ListNode* tmp = slow->next;
            slow->next = second;
            second = slow;
            slow = tmp;
        }

        // 3. Merge
        ListNode *first = head;
        while(second){
            ListNode *tmp1 = first->next;
            first->next = second;
            
            ListNode *tmp2 = second->next;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
