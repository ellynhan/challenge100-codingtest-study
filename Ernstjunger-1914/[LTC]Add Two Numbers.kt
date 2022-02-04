/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var result: Int = 0
        var order: Int = 1
        var copyl1 = l1
        var copyl2 = l2
        val rootnode = ListNode(0)
        var resultnode = rootnode
        var prevnode = resultnode
        
        while(copyl1 != null) {
            var one: Int = copyl1?.`val`
            
            if(copyl2 != null) {
                one += copyl2?.`val`
            }
            
            one += resultnode.`val`
            
            resultnode.`val` = (one % 10)
            resultnode.next = ListNode(0)
            prevnode = resultnode
            resultnode = resultnode.next
            
            if(one >= 10) {
                resultnode.`val` += (one / 10)
            }
            
            copyl1 = copyl1?.next
            copyl2 = copyl2?.next
        }
        
        while(copyl2 != null) {
            var one: Int = copyl2?.`val`
            one += resultnode.`val`
            
            resultnode.`val` = (one % 10)
            resultnode.next = ListNode(0)
            prevnode = resultnode
            resultnode = resultnode.next
            
            if(one >= 10) {
                resultnode.`val` += (one / 10)
            }
            
            copyl2 = copyl2?.next
        }
        
        if(resultnode.`val` == 0) {
            resultnode = prevnode
            resultnode.next = null
        }
        return rootnode
    }
}