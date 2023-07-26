import sys

input = sys.stdin.readline

sen = input().rstrip()

while sen != ".":
    lst = list(sen)
    
    bra = []
    
    for st in lst:
        
        if st == '[' or st == '(':
            bra.append(st)
        elif st == ']':
            if len(bra) != 0 and bra[-1] == '[':
                bra.pop()
            else:
                bra.append(']')
                break
        elif st == ')':
            if len(bra) != 0 and bra[-1] == '(':
                bra.pop()
            else:
                bra.append(')')
                break
                
    if len(bra) == 0:
        print('yes')
    else:
        print('no')
        
    sen = input().rstrip()