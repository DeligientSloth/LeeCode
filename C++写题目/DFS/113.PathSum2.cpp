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
public:
    vector<vector<int>> ret;
    vector<int> path;
    void helper(TreeNode* root,int sum){
        path.push_back(root->val);
        sum-=root->val;
        if(sum==0&&root->left==NULL&&root->right==NULL) ret.push_back(path);
        if(root->left!=NULL) helper(root->left,sum);
        if(root->right!=NULL) helper(root->right,sum);
        path.pop_back();//返回上一层
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return ret;
        helper(root,sum);
        return ret;
    }
};
