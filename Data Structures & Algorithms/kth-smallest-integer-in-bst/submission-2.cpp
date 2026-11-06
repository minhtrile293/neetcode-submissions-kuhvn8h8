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
    set<int>se;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        int kth = 1;
        for(auto it = se.begin(); it != se.end(); it++)
        {
            if(kth == k)
                return *it;
            kth++; 
        }
    }
    void dfs(TreeNode* root){
        if(!root) return;
        se.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
