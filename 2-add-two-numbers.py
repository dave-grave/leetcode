# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        first = l1
        second = l2 
        carry = 0
        head = res = ListNode(0)

        while (first is not None and second is not None):
            total = first.val + second.val + carry
            res.val = total % 10
            carry = total // 10
            first = first.next
            second = second.next

            if first is None and second is None:
                break

            res.next = ListNode(0)
            res = res.next


        while first is not None:
            total = first.val + carry
            first = first.next

            res.val = total % 10
            carry = total // 10
            if (first is None):
                break
            res.next = ListNode(0)
            res = res.next

        while second is not None:
            total = second.val + carry
            second = second.next
            res.val = total % 10
            carry = total // 10
            if second is None:
                break
            res.next = ListNode(0)
            res = res.next


        # check for carry on last number
        if carry == 1:
            res.next = ListNode(1)

        return head