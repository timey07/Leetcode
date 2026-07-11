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
    // private:
    // void recursive(vector<int> &ans,TreeNode* Node){
    //     if(Node==NULL) return;
        
    //     recursive(ans,Node->left);
    //     ans.push_back(Node->val);
    //     recursive(ans,Node->right);
    // }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        // recursive(ans,root);
        // return ans;
        stack<TreeNode*> st;
        TreeNode* Node=root;
        while(true){
            if(Node){
                st.push(Node);
                Node=Node->left;
            }
            else{
                if(st.empty()) break;
                Node=st.top();
                st.pop();
                ans.push_back(Node->val);
                Node=Node->right;
            }
            
        }
        return ans;
    }
};
