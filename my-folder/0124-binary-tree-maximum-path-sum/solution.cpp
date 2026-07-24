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
    private:
    int solve(int &ans,TreeNode* Node){
        if(Node==NULL) return 0;
        int leftsum=max(0,solve(ans,Node->left));
        int rightsum=max(0,solve(ans,Node->right));
        ans=max(ans,Node->val+leftsum+rightsum);
        return Node->val+max(leftsum,rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=root->val;
        solve(ans,root);
        return ans;
    }
};
