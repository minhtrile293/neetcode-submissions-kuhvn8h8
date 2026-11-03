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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        unordered_map<TreeNode*, int> mp;
        stack<TreeNode*> st;
        TreeNode* node = root->left;
        TreeNode* last = nullptr;
        
        st.push(root);
        while(!st.empty()){
            if(node){
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                if(node->right == nullptr || last == node->right){
                    st.pop();
                    int left = mp[node->left];
                    int right = mp[node->right];
                    if(abs(left - right) > 1) return false;
                    mp[node] = 1 + max(left, right);
                    last = node;
                    node = nullptr;
                } else {
                    node = node->right;
                }
            }
        }
        return true;
    }
};
