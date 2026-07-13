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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int rev=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> list(n);
            for(int i=0;i<n;++i){
                TreeNode* Node=q.front();
                q.pop();
                if(Node->left) q.push(Node->left);
                if(Node->right) q.push(Node->right);
                if(rev) list[n-i-1]=(Node->val);
                else list[i]=(Node->val);
            }
            ans.push_back(list);
            rev^=1;
        }
        return ans;
    }
};
