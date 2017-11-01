/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
Initialize current node to dummy head of the returning list.
Initialize carry to 00.
Initialize pp and qq to head of l1l1 and l2l2 respectively.
Loop through lists l1l1 and l2l2 until you reach both ends.
Set xx to node pp's value. If pp has reached the end of l1l1, set to 00.
Set yy to node qq's value. If qq has reached the end of l2l2, set to 00.
Set sum = x + y + carrysum=x+y+carry.
Update carry = sum / 10carry=sum/10.
Create a new node with the digit value of (sum \bmod 10)(summod10) and set it to current node's next, then advance current node to next.
Advance both pp and qq.
Check if carry = 1carry=1, if so append a new node with digit 11 to the returning list.
Return dummy head's next node.
*/
/*
两种写法，第二种把第一种的两个判断语句结合成一个，效率提高不少
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode* p=l1;
        //ListNode* q=l2;
        ListNode* node=new ListNode(0);//初始化头结点,返回分配内存地址
        ListNode* headnode=node;
        int temp=0;
        while(l1!=NULL||l2!=NULL){
            int x=l1==NULL? 0:l1->val;//比较容易出错，其中一个到达链表尾部就取0值
            int y=l2==NULL? 0:l2->val;
            int sum=x+y+temp;
            temp=sum/10;
            node->next=new ListNode(sum%10);
            node=node->next;
            if(l1!=NULL) l1=l1->next;//链表操作过程中，需要判断是否达到链表尾部
            if(l2!=NULL) l2=l2->next;
        }
        if(temp!=0) node->next=new ListNode(temp);//如果还有余数，就增加一位
        return headnode->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //ListNode* p=l1;
        //ListNode* q=l2;
        ListNode* node=new ListNode(0);//初始化头结点,返回分配内存地址
        ListNode* headnode=node;
        int temp=0;
        while(l1!=NULL||l2!=NULL){
            int sum=0;
            if(l1){
                sum=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=temp;
            if(sum>9){
                sum-=10;
                temp=1;
            }
            else temp=0;
            node->next=new ListNode(sum);
            node=node->next;
        }
        if(temp!=0) node->next=new ListNode(temp);
        return headnode->next;
    }
};
