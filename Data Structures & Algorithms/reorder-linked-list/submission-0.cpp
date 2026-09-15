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
        ListNode* node = head;
        int n = 0;
        while(node){
            n++;
            node = node->next;
        }
        
        node = head;
        ListNode* curr = nullptr;
        for(int i = 0; i < (n + 1)/2; i++){
            if(curr){
                node->next = curr;
                node = node->next; 
            }
            ListNode* tail = node;
            for(int j = i + 1; j < n - i; j++){
                tail = tail->next;
            }
            tail->next = nullptr;
            curr = node->next;
            if(node != tail){
                node->next = tail;
                node = node->next;
            }
        }
    }
};

