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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = nullptr;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        if(curr1 && curr2){
            if(list1->val < list2->val){
                list = list1;
            } else{
                list = list2;
            }
        } else if(curr1){
            list = list1;
        } else {
            list = list2;
        }
        while(curr1 && curr2){
            ListNode* temp = nullptr;
            if(curr1->val < curr2->val){
                while(curr1->next && (curr1->next->val <= curr2->val)){
                    curr1 = curr1->next;
                }
                temp = curr1->next;
                curr1->next = curr2;
                curr1 = temp;
            } else { 
                while(curr2->next && (curr2->next->val <= curr1->val)){
                    cout << curr2->next->val << " " << curr1->val << endl;
                    curr2 = curr2->next;
                }
                temp = curr2->next;
                curr2->next = curr1;
                curr2 = temp;
            }
        }
        return list;
    }
};
