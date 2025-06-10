# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        slow = head
        fast = head

        for i in range(n):
            fast = fast.next
        
        if fast is None:
            head = head.next
            return head

        prev = None
        while fast is not None:
            fast = fast.next
            prev = slow
            slow = slow.next

        prev.next = slow.next        

        return head