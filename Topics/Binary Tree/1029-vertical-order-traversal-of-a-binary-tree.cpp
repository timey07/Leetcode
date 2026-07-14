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
    void dfs(int row,int col,TreeNode* node,vector<tuple<int,int,int>>&nodes){
        if(node==NULL) return;
        nodes.push_back({col,row,node->val});

        dfs(row+1,col-1,node->left,nodes);
        dfs(row+1,col+1,node->right,nodes);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
        dfs(0,0,root,nodes);

        sort(nodes.begin(),nodes.end());

        vector<vector<int>> ans;
        int prev=INT_MIN;
        for( auto [col, row, val]:nodes){
            if(col!=prev){
                ans.push_back({});
                prev=col;
            }

            ans.back().push_back(val);
        }
        return ans;
    }
};
