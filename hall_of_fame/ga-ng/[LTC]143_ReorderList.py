# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        ######################################
        ## change rule                      ##
        ## 0 -> n -> 1 -> n-1 -> 2 -> ...   ##
        ######################################
        length = 0
        cur = head

        while cur:
            length += 1
            cur = cur.next

        half = length//2

        ###########
        ## Split ##
        ###########
        cur = head
        list1, list2 = ListNode(0, None), ListNode(0, None)
        temp1, temp2 = list1, list2

        i = 0
        while cur:  ## 우선 2개의 list로 나누자.
            if i < half:    ## list1 에 넣기
                temp1.next = cur
                temp1 = temp1.next
            else:                       ## list2 에 넣기
                temp2.next = cur
                temp2 = temp2.next

            i += 1
            cur = cur.next

        temp1.next = None
        temp2.next = None

        list1, list2 = list1.next, list2.next


        #############
        ## reverse ##
        #############
        cur, pre = list2, None

        while cur:
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp

        list2 = pre


        ###########
        ## merge ##
        ###########
        ans = temp = ListNode(0,None)

        i = 0
        while list1 and list2:
            if i % 2 == 0:
                temp.next = list1
                list1 = list1.next
            else:
                temp.next = list2
                list2 = list2.next

            i += 1
            temp = temp.next


        ############
        ## Remain ##
        ############
        if not list1:
            temp.next = list2
        else:
            temp.next = list1

        head = ans.next

