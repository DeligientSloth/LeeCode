108. Convert Sorted Array to Binary Search Tre
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
    void helperToBST(TreeNode*& root,vector<int>& nums,int low,int high){
        if(low>high) return;
        int mid=low+((high-low)>>1);
        root=new TreeNode(nums[mid]);
        helperToBST(root->left,nums,low,mid-1);
        helperToBST(root->right,nums,mid+1,high);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        helperToBST(root,nums,0,nums.size()-1);
        return root;
    }
};
