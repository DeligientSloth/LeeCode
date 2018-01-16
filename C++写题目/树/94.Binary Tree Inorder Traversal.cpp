class Solution {
public
    vectorint inorderTraversal(TreeNode root) {
        vectorint ret;
        if(!root) return ret;
        stackTreeNode stack;
        TreeNode node=root;
        while(true){
            while(node){
                stack.push(node);
                node=node-left;
            }
            if(stack.empty()) break;
            node=stack.top();stack.pop();
            ret.push_back(node-val);
            node=node-right;转到右子树
        }
        return ret;
    }
};
