class node:
    def __init__(self):
        self.pre = None
        self.nxt = None
        self.removed = False

def solution(n, k, cmd):
    linkedList = [node() for _ in range(n)]
    for i in range(1, n):
        linkedList[i].pre = linkedList[i-1]
        linkedList[i-1].nxt = linkedList[i]
    deleted = []

    p = linkedList[k]
    for c in cmd:
        if c[0] == 'U':
            cnt = int(c[2:])
            while cnt: 
                p = p.pre
                cnt -= 1
        elif c[0] == 'D':
            cnt = int(c[2:])
            while cnt: 
                p = p.nxt
                cnt -= 1
        elif c[0] == 'C':
            deleted.append(p)
            p.removed = True
            if p.pre: 
                p.pre.nxt = p.nxt
            if p.nxt:
                p.nxt.pre = p.pre
                p = p.nxt
            else:
                p = p.pre
        else:
            x = deleted.pop()
            x.removed = False
            if x.pre:
                x.pre.nxt = x
            if x.nxt:
                x.nxt.pre = x
    
    answer = ''
    for i in range(n):
        if linkedList[i].removed: answer += 'X'
        else: answer += 'O'
    
    return answer
  
"""
이 코드에서 핵심은
삭제할 때 이전노드, 다음노드 정보를 지우지 않고 removed만 변경하기 때문에 복구 기능의 구현이 간편하다.
"""
