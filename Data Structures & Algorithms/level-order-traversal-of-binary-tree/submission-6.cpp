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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lists;
        queue<TreeNode*> q;
        if(!root) return lists;
        q.push(root);
        while(!q.empty()){
            vector<int> nestedList;
            int level = q.size();
            while(level--){
                TreeNode* node = q.front();
                q.pop();
                nestedList.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            lists.push_back(nestedList);
        }
        return lists;
    }
};
