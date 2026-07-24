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
    int solve(TreeNode* Node,int height){
        if(Node==NULL) return 0;
        int lh=solve(Node->left,height);
        int rh=solve(Node->right,height);
        if(abs(lh-rh)>1 || lh==-1 || rh==-1) return -1;
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(solve(root,0)==-1) return false;
        return true;
    }
};
