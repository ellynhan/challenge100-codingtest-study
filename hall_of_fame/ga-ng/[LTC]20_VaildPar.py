class Solution:
    def isValid(self, s: str) -> bool:
        stack = []


        for char in s:
            if char == '(' or char == '[' or char == '{':
                stack.append(char)
            else:
                if not stack:
                    return False

                top = stack.pop()
                combine = top + char
                # print(combine, stack)
                if combine == '()' or combine == '[]' or combine == '{}':
                    continue
                else:
                    return False
        
        
        if stack:
            return False
        else:
            return True