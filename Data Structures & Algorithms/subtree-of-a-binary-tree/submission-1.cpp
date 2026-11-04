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
    bool checkSubtree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            return checkSubtree(root->left, subRoot->left) * checkSubtree(root->right, subRoot->right);
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            if(node->val == subRoot->val){
                if(checkSubtree(node, subRoot)){
                    return true;
                }
            } 
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);
        }
        return false;
    }
};
