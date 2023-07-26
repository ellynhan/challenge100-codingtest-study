def hasCycle(slef, head):
    
    if not head or not head.next:
        return False
    
    slow = head.next
    fast = head.next.next
    
    while slow and fast and fast.next:
        if slow == fast:
            return True
        
        slow = slow.next
        fast = fast.next.next
        
    
    return False