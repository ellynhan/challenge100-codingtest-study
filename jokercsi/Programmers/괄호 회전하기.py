def solution(s):
    count = 0
    stack = []
    Dict = {'{' : '}', '[' : ']', '(' : ')'}
    saveValue = ""
    
    s = list(s)
    
    for i in range(len(s)):
        # rotation
        element = s.pop(0)
        s.append(element)
        
        # check correct bracket
        for j in s:
            if j == '{' or j == '[' or j == '(':
                stack.append(j)
            else:
                if stack == []:
                    stack.append(j)
                else:
                    for key, value in  Dict.items():
                        if stack[-1] == key:
                            saveValue = value
                        
                    
                    if j == saveValue:
                        stack.pop()
            
        if stack == []:
            count += 1
        stack = [] 
    
    return count
