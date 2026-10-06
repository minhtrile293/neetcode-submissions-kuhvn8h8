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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* l = &dummy;
        int carry = 0;
        while(l1 && l2){
            l->next = new ListNode;
            l = l->next;
            
            int value = l1->val + l2->val + carry;
            l->val = value % 10;
            carry = value / 10;

            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 || l2){
            l->next = new ListNode;
            l = l->next;
            int value = 0;
            if(l1){
                value = l1->val + carry;
                 l1 = l1->next;
            }
            else{
                value = l2->val + carry;
                l2 = l2->next;
            }
            l->val = value % 10;
            carry = value / 10;
        }
        if(carry != 0){
            l->next = new ListNode;
            l = l->next;
            l->val = carry;
        }
        return dummy.next;
    }
};

