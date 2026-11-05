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
            queue<TreeNode*> descentList;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                nestedList.push_back(node->val);
                if(node->left)
                    descentList.push(node->left);
                if(node->right)
                    descentList.push(node->right);
            }
            if(!descentList.empty())
                q = move(descentList);
            lists.push_back(nestedList);
        }
        return lists;
    }
};
