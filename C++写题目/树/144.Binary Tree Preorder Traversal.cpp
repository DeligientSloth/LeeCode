
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x)  val(x), left(NULL), right(NULL) {}
  };

class Solution {
public
    vectorint preorderTraversal(TreeNode root) {
        vectorint ret;
        if(root==NULL) return ret;
        TreeNode node=root;
        stackTreeNode S;
        while(true){
            while(node){
                ret.push_back(node-val);
                if(node-right) S.push(node-right);
                node=node-left;
            }
            if(S.empty()) break;没有要遍历的右子树
            node=S.top();S.pop();
        }
        return ret;
    }
};
