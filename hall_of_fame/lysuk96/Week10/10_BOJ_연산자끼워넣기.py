# https://www.acmicpc.net/problem/14888
# 1트 : 연산자의 우선순위를 결정하고 했다가 틀림
# 2트 : 브루트포스로 푸니까 풀림... 어디가 백트래킹이지..?

def calculate(a, b, ys):
    if ys == 0:
        return a + b
    elif ys == 1:
        return a - b
    elif ys ==2 :
        return a*b
    elif ys ==3:
        if a<0:
            return -((-a)//b)
        else: return a//b
    
def tracking(idx, result):
    global m,M
    # print(idx, pmmd, result)
    if idx == N:
        # print(result)
        m = min(m, result)
        M = max(M, result)
        return
    for ys in range(4):
        if pmmd[ys] !=0:
            pmmd[ys]-=1
            tracking(idx+1, calculate(result, num[idx], ys))
            pmmd[ys]+=1


N = int(input())
num = list(map(int,input().split(" ")))
pmmd = list(map(int, input().split(" "))) # 더하기, 빼기, 곱하기, 나누기 연산자 갯수

global m, M
m, M = 1000000000, -1000000000

tracking(1, num[0])
print(M, m)

# 우선순위 정했다가 틀린 코드
# max_pri = [1, 3, 0, 2]
# min_pmmd = max_pmmd[:]
# min_pri = [0, 3, 1, 2]

# result = num[0]
# for i in range(1, N+1):
#     # print(max_pmmd, min_pmmd)
#     for mp in max_pri:
#         if max_pmmd[mp] == 0:
#             continue
#         else:
#             max_pmmd[mp]-=1
#             if mp == 0:
#                 M = M+num[i]
#             elif mp == 1:
#                 M = M-num[i]
#             elif mp == 2:
#                 M = M * num[i]
#             elif mp == 3:
#                 if M < 0 :
#                     M = -(abs(M) // num[i])
#                 else: M = M // num[i]
#             break
#     for mp in min_pri:
#         if min_pmmd[mp] == 0:
#             continue
#         else:
#             min_pmmd[mp]-=1
#             if mp == 0:
#                 m = m+num[i]
#             elif mp == 1:
#                 m = m-num[i]
#             elif mp == 2:
#                 m = m * num[i]
#             elif mp == 3:
#                 if m < 0:
#                     m= -(abs(m) // num[i])
#                 else: m = m // num[i]
#             break


