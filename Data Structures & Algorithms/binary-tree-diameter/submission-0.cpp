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
    int findDiameter(TreeNode* root, int& maxLength){
        if(!root) return 0;
        
        int leftLength = 1 + findDiameter(root->left, maxLength); 
        int rightLength = 1 + findDiameter(root->right, maxLength);
        maxLength = max(leftLength + rightLength - 1, maxLength);
        
        return max(leftLength,rightLength);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxLength = 1;
        int tmp = findDiameter(root, maxLength);
        return maxLength - 1;
    }
};
