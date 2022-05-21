class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        true_table = {
            '(':')',
            '{':'}',
            '[':']'
            
        }
        for string in s:
            if string in ['(', '{', '[']:
                stack.append(string)
            else:
                if not stack:
                    return False
                tmp = stack.pop()
                if true_table[tmp] != string:
                    return False
                
        return len(stack)==0
    
