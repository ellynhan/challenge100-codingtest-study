___
### 코드
```python
import sys
# from collections import deque
input = sys.stdin.readline

# input
S, P = map(int, input().split())
dna = input()
min_ACGT = list(map(int, input().split()))

dp = [[0,0,0,0] for _ in range(S)]

# DP
for i in range(S):
    if i > 0: dp[i] = dp[i-1].copy()
        
    ch = dna[i]
    if(ch == 'A'): dp[i][0] += 1
    elif(ch == 'C'): dp[i][1] += 1
    elif(ch == 'G'): dp[i][2] += 1
    elif(ch == 'T'): dp[i][3] += 1
        
    if(i < P): continue

    ch_P_before = dna[i-P]
    
    if(ch_P_before == 'A'): dp[i][0] -= 1
    elif(ch_P_before == 'C'): dp[i][1] -= 1
    elif(ch_P_before == 'G'): dp[i][2] -= 1
    elif(ch_P_before == 'T'): dp[i][3] -= 1

ans = 0

# ans
for i in range(P-1, S):
    flag = True
    for j in range(4):
        if dp[i][j] < min_ACGT[j]: 
            flag = False
    if flag:
        ans += 1

print(ans)
```
<br>

### 결과
![image](https://github.com/minsuhan1/challenge100-codingtest-study/assets/50696567/08e0a732-6f13-453d-a444-d37e2a405b74)

<br>

### 풀이 방법
- `DP` 방식으로 해결하였다
- DP[i] = DNA 문자열의 i번째 문자로 끝나는 길이 P인 부분문자열에서의 A,C,G,T 개수
- 예를들어 ACCATGGACTGA 문자열에서 P가 7일 때 DP[11]을 구하면 ATGGACT에서의 A,C,G,T 개수를 구하여 [2,1,2,2] 가 된다
- DP[i]를 쉽게 구하려면 DP[i-1]에서의 각 문자 개수에서 i번째 문자의 개수만 증가시키고, DP[i-1]에서 사용됐던 부분문자열의 첫 문자는 이제 포함되지 않으므로 해당 문자의 개수는 1 감소시키면 된다.
- 이런식으로 DP 배열을 구한 다음, DP를 순회하면서 최소 A,C,G,T 개수 조건에 부합하는 부분문자열의 개수를 카운트해주었다.
___
