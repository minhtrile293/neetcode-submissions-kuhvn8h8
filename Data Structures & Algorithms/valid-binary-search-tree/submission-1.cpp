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
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    bool dfs(TreeNode* root, TreeNode* minVal, TreeNode* maxVal){
        if(!root) return true;
        if(minVal && root->val <= minVal->val)
            return false;
        if(maxVal && root->val >= maxVal->val)
            return false;
        return dfs(root->left, minVal, root) && dfs(root->right, root, maxVal);
    }
};


// minVal 0 
// maxVal 0

// -300, minVal = null, maxVal = 0;
// -301, minVal = null, maxVal = -300;
// -200, minVal = -300, maxVal = 0
// -401, minVal = -300, maxVal = -200
// -202, minVal = -200, maxVal = 0


//                 0
//     -300                1000
//  -301    -200.      -1 
//      -401.  -202.
        



