/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void helperToBST(TreeNode*&root,ListNode* head){
        if(head==NULL) {root=NULL;return;}
        if(head->next==NULL) {root=new TreeNode(head->val);return;}
        ListNode *fast=head,*slow=head,*last=slow;
        while(fast->next&&fast->next->next){
            last=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //ListNode* midnode=slow;
        fast=slow->next;
        root=new TreeNode(slow->val);
        last->next=NULL;
        if(head!=slow) helperToBST(root->left,head);
        //helperToBST(root->right,midnode->next);
        helperToBST(root->right,fast);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
        TreeNode* root=NULL;
        helperToBST(root,head);
        return root;
    }
};


class Solution {
public:
    void helperToBST(TreeNode*&root,ListNode* head,ListNode* tail){
       //用head->tail-1的链表数据建立二叉树，不包含tail
       //找到head->tail的中点
        if(head==tail) {root=NULL;return;}
        if(head->next==tail) {root=new TreeNode(head->val);return;}
        ListNode *fast=head,*slow=head;
        while(fast->next!=tail&&fast->next->next!=tail){
            slow=slow->next;fast=fast->next->next;
        }
        root=new TreeNode(slow->val);
        helperToBST(root->left,head,slow);
        helperToBST(root->right,slow->next,tail);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
        TreeNode* root=NULL;
        helperToBST(root,head,NULL);
        return root;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* helperToBST(ListNode* head,ListNode* tail){
       //用head->tail-1的链表数据建立二叉树，不包含tail
       //找到head->tail的中点
        if(head==tail) return NULL;
        if(head->next==tail) return new TreeNode(head->val);
        ListNode *fast=head,*slow=head;
        while(fast->next!=tail&&fast->next->next!=tail){
            slow=slow->next;fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->val);
        root->left=helperToBST(head,slow);
        root->right=helperToBST(slow->next,tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
        return helperToBST(head,NULL);
    }
};
class Solution {
public:
    TreeNode* InOrderToBST(ListNode*& head,int low,int high){//用low->high的数据建立BST
        if(head==NULL||low>high) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);//这里如果加上或者low==high的话不可取，这样的话需要head=head->next
        int mid=low+((high-low)>>1);
        TreeNode* leftNode=InOrderToBST(head,low,mid-1);
        //建立根节点
        TreeNode* root=new TreeNode(head->val);
        head=head->next;
        root->left=leftNode;
        //建立右子树
        root->right=InOrderToBST(head,mid+1,high);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return new TreeNode(head->val);
        int len=0;
        ListNode* node=head;
        while(node){
            len++;
            node=node->next;
        }
        return InOrderToBST(head,0,len-1);
    }
};
