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
        int length = 0;
        ListNode* node = head;
        while(node){
            length++;
            node = node->next;
        }
    
        int index = length - n;
        if(index == 0){
            ListNode* tmp = head->next;
            head->next = nullptr;
            head = tmp;
            return head;
        }

        node = head;
        for(int i = 0; i < index; i++){
            if(i == index - 1){
                ListNode *tmp = node->next;
                node->next = tmp->next;
                tmp->next = nullptr;
                return head;
            }
            node = node->next;
        }
    }
};
