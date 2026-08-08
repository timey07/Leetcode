/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    bool solve(TreeNode* Node,TreeNode* p,TreeNode* q,TreeNode*& ans){
        if(Node==NULL) return false;
        bool left=solve(Node->left,p,q,ans);
        bool right=solve(Node->right,p,q,ans);
        if(left && right) ans=Node;
        if((Node==p || Node==q) && (left || right)) ans=Node;
        return (left || right || Node==p || Node==q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;
        TreeNode* ans;
        solve(root,p,q,ans);
        return ans;
    }
};
