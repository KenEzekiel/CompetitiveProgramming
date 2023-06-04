# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        iter_1 = head
        prev_1 = iter_1
        count = 0
        while count < left-1:
            print("loop 1", iter_1.val)
            prev_1 = iter_1
            iter_1 = iter_1.next
            count += 1
        iter = iter_1
        print("prev:", prev_1.val, "iter:", iter_1.val)
        while count < right:
            print("loop 2", iter.val)
            prev = iter
            iter = iter.next
            if count == right-1:
                prev.next = None
            count += 1
        print("prev:", prev.val, "iter:", iter.val)

        # prev_1 -> head, iter -> tail

        list_mid = iter_1
        # i = list_mid
        # while i:
        #     print(i.val)
        #     i = i.next
        # list_rev = self.reverseList(list_mid)
        prev = None
        curr = iter_1
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        # i = list_rev
        # while i:
        #     print(i.val)
        #     i = i.next
        prev_1.next = prev
        iter_1.next = iter

        return head

# five = ListNode(5)
# four = ListNode(4, five)
# three = ListNode(3, four)
# two = ListNode(2, three)
# one = ListNode(1, two)
two = ListNode(5)
one = ListNode(3, two)

sol = Solution()
i = sol.reverseBetween(one, 2, 4)
# i = sol.reverseList(one)

while i:
    print(i.val)
    i = i.next
