/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int kth = 0;
        stack<TreeNode*> st;
        map<TreeNode*, int> visited;
        if(root->right)
            st.push(root->right);
        st.push(root);
        if(root->left)
            st.push(root->left);
        visited[root] = 1;

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(visited.count(node)){
                kth++;
                if(kth == k)
                    return node->val;
                continue;
            }
            if(node->left == nullptr){
                kth++;
                if(kth == k)
                    return node->val;
                else if(node->right) {
                    st.push(node->right);
                }
            } else {
                if(node->right)
                    st.push(node->right);
                st.push(node);
                st.push(node->left);
            }
            visited[node] = 1;
        }
        return root->val;
    }

};
