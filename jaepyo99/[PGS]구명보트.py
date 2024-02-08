
from collections import deque
def solution(peoples, limit)
    cnt = 0
    peoples.sort(reverse=True)
    print(peoples)
    f=0
    r=len(peoples)-1
    while(f=r)
        cnt+=1
        if(peoples[f]+peoples[r]=limit)
            r-=1
        f+=1

    return cnt