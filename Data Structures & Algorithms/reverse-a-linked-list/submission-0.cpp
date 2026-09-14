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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode* list = new ListNode(head->val);
        ListNode* i = head->next;
        while(i != nullptr){
            ListNode *temp = new ListNode(i->val);
            temp->next = list;
            list = temp;
            i = i->next;
        }
        return list;
    }
};