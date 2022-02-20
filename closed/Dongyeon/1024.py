#백준 1024번 수열의 합
#실버 2

N, L = map(int, input().split())

rest = [0.5, 0]

def find(N, L):
    while True:
        if ((N % L) / L) == rest[L % 2]:
            break
        else:
            L += 1
        if L*(L+1) > 2 * N:
            return -1
        if L > 100:
            return -1
    if L%2 == 1:
        mid = int(N/L)
        ans = [mid]
        for i in range(int((L-1)/2)):
            ans.append(mid-1-i)
            ans.append(mid+1+i)
        ans.sort()
        if ans[0] <0:
            return find(N, L+1)
        return ans
    else:
        midl, midr = int(N/L-0.5), int(N/L+0.5)
        ans = [midl, midr]
        for i in range(int((L-2)/2)):
            ans.append(midl-i-1)
            ans.append(midr+i+1)
        ans.sort()
        if ans[0] < 0:
            return find(N, L + 1)
        return ans

answer = find(N, L)
if answer == -1:
    print(answer)
else:
    print(" ".join(map(str, find(N, L))))

