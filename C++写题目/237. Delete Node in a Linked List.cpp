/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //node是要删除的节点
        ListNode* p=node->next;
        node->val=p->val;
        node->next=p->next;
    }
};
