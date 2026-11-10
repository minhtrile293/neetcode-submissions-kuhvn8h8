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
        // 1 2 3 4
        // 4 3 2 1

        // //Root → Left → Right 1 2 3 4
        // //Left → Root → Right 2 1 3 4
        // a[2] = 0, a[1] = 1, a[3] = 2, a[4] = 3
        // root->left = 2
        // root->right = 3

    map<int, int> indexes;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            indexes[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int rootIndex = 1;
        dfs(preorder, root->left, 0, indexes[root->val] - 1, rootIndex);
        dfs(preorder, root->right, indexes[root->val] + 1, inorder.size() - 1, rootIndex);
        return root;
    }

    void dfs(vector<int>& preorder, TreeNode* &root, int l, int r, int &rootIndex){
       if(l > r || l < 0 || r < 0) return;
       if(indexes[preorder[rootIndex]] >= l && indexes[preorder[rootIndex]]<= r){
        
            root = new TreeNode(preorder[rootIndex]);
            rootIndex++;
            dfs(preorder, root->left, l, indexes[root->val] - 1, rootIndex);
            dfs(preorder, root->right, indexes[root->val] + 1, r, rootIndex);
       }
    }
};
