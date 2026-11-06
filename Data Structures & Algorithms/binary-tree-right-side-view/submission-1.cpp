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
    vector<int> nodeList;
    int level = -1;

    vector<int> rightSideView(TreeNode* root) {
        if(root){
            dfs(root, 0);
        }
        return nodeList; 
    }

    void dfs(TreeNode* root, int currLevel){
        if(currLevel > level){
            nodeList.push_back(root->val);
            level++;
        }
        currLevel++;
        if(root->right){
            dfs(root->right, currLevel);
        }
        if (root->left){
            dfs(root->left, currLevel);
        }
    }
};
