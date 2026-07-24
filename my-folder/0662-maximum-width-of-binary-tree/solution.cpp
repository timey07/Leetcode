/**
 * Definition for a binary tree it.
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        long long ans=1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        while(!q.empty()){
            long long n=q.size();
            long long start=q.front().second;
            long long end=q.back().second;

            ans=max(ans,end-start+1);

            while(n--){
                auto it=q.front();
                q.pop();

                long long idx=it.second-start;

                if(it.first->left){
                    q.push({it.first->left,2*idx+1});
                }

                if(it.first->right){
                    q.push({it.first->right,2*idx+2});
                }
            }
        }

        return ans;
    }
};
