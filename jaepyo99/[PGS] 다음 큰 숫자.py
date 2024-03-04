def binary(n):
    binary=""
    while(n):
        binary+=str(n%2)
        n=n//2
    return binary[::-1]
def cal_cnt(binary):
    cnt=0
    for b in binary:
        if(b=='1'):
            cnt+=1
    return cnt
    
def solution(n):
    cnt=cal_cnt(binary(n))
    while(True):
        n+=1
        up_cnt=cal_cnt(binary(n))
        if(cnt==up_cnt):
            return n
