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
    void solve(TreeNode* node,int val){
        while(true){
            if(node->val>val){
                if(node->left==NULL){
                    TreeNode* add= new TreeNode(val);
                    node->left=add;
                    break;
                }
                else node=node->left;
                
            }
            if(node->val<val){
                if(node->right==NULL){
                    TreeNode* add= new TreeNode(val);
                    node->right=add;
                    break;
                }
                else node=node->right;
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* t= new TreeNode(val);
            return t;
        }
        solve(root,val);
        return root;
    }
};
