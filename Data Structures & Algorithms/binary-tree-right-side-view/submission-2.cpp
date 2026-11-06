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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nodeList;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            TreeNode* rightNode = nullptr;
            for(int i = 0; i < len; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    rightNode = node;
                    q.push(node->left);
                    q.push(node->right);
                }

            }
            if(rightNode)
                nodeList.push_back(rightNode->val);
        }
        return nodeList;
    }
};
