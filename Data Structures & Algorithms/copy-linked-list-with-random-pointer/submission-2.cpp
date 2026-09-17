/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* curr1 = head;    
        Node* curr2 = &dummy;
        
        map<Node*, int>indexes1;
        vector<Node*>indexes2;

        int index = 0;
        while(curr1){
            curr2->next = new Node(curr1->val);
            curr2 = curr2->next;

            indexes1[curr1] = index;
            indexes2.push_back(curr2);
            curr1 = curr1->next;
            index++;
        }

        curr1 = head;
        curr2 = dummy.next;
        while(curr1){
            if(curr1 && curr1->random){
                int point = indexes1[curr1->random];
                curr2->random = indexes2[point];
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return dummy.next;
    }
};
