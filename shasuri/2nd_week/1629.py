# [BOJ] 곱셈 / 실버1 / 1시간
# https://www.acmicpc.net/problem/1629

def divCon(div) :
    if div == 0 :
        return 1
    
    tmp = divCon(div // 2)
    tmp = tmp * tmp % C

    if div % 2 == 0 : 
        return tmp
    
    return A * tmp % C

if __name__ == "__main__" :
    ABC = list(map(int,input().split()))
    
    A = ABC[0]
    B = ABC[1]
    C = ABC[2]

    print(divCon(B))
