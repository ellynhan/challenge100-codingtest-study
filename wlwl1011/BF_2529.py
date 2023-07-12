import sys, os, io, atexit
import copy
from collections import deque
input = lambda: sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda: os.write(1, stdout.getvalue()))

def dfs(st , number, inequality):

    if len(st) > k+1:
        return
    if len(st) == k+1: #우리는 k+1의 개수만큼만 숫자만 필요하니께
        answer_list.append(st)
        return 
    if arr[inequality] == '<':
       
        #number 보다 큰 수가 와야함
        for i in range(10):
          
            if str(i) in st:
                continue
            if number >i: #만약 작은수면 저리가셈
                continue 
            #위의 경우가 아니라면 새로운 숫자로 임명될 자격이 있다!
            temp_st = st
            st += str(i)
           
            dfs(st, i,inequality+1)
            st = temp_st
            
    elif arr[inequality] == '>':
        
        #작은 수 와야함        
          for i in range(9):
            if str(i) in st:
                continue
            if number < i: #만약 큰 수면 저리가셈
                continue 
            #위의 경우가 아니라면 새로운 숫자로 임명될 자격이 있다!
            temp_st = st
            st += str(i)
            dfs(st, i, inequality+1)
            st = temp_st
               

k = int(input()) #부등호 문자의 개수

arr = list(map(str,input().split()))




global answer_list
answer_list = []

i = 0
    #그럼 숫자를 골라보자
for index in range(10):
    s = ''
    s += str(index)
    dfs(s, index,i)


answer_list.sort(key = lambda x : int(x))
print(answer_list[len(answer_list)-1])
print(answer_list[0])