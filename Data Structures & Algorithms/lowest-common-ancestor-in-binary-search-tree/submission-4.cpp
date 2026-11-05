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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)  {
        map<TreeNode*, TreeNode*> ancestor;
        stack<TreeNode*> st;
        bool checkP = true;
        bool checkQ = true;
        st.push(root);
        ancestor[nullptr] = nullptr;
        ancestor[root] = nullptr;
        while((checkP || checkQ) && !st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            if(node == p)
                checkP = false;
            else if(node == q)
                checkQ = false;
            
            if(node->right){
                st.push(node->right);
                ancestor[node->right] = node;
            }
            if(node->left){
                st.push(node->left);
                ancestor[node->left] = node;
            }
        }

        TreeNode* ancestorP = ancestor[p];
        TreeNode* ancestorQ = ancestor[q];
        map<TreeNode*, int> track;
        track[p] = 1;
        track[q] = 1;
        while(ancestorP != nullptr || ancestorQ != nullptr){
            if(ancestorP && track.count(ancestorP)){
                return ancestorP;
            }
            track[ancestorP] = 1;
            if(ancestorQ && track.count(ancestorQ)){
                return ancestorQ;
            }
            track[ancestorQ] = 1;
            ancestorP = ancestor[ancestorP];
            ancestorQ = ancestor[ancestorQ];
        }
        return root;
    }
};
