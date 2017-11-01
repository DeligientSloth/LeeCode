# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        node=ListNode(0)
        cur=node
        carry=0
        while l1 or l2:
            sum=0
            if l1:sum=l1.val;l1=l1.next
            if l2:sum+=l2.val;l2=l2.next
            sum+=carry
            if sum>9:
                #cur.next=ListNode(int(sum%10))，if里面cur会被认为是nonetype？？？
                sum-=10
                carry=1
            else:carry=0
            cur.next=ListNode(sum)
            cur=cur.next
        if carry>0:cur.next=ListNode(carry)
        return node.next
