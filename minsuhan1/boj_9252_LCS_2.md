___
### 코드
```python
import sys
input = sys.stdin.readline

s1 = input().rstrip()
s2 = input().rstrip()

l1 = list(s1)
l2 = list(s2)

def LCS():
    dp = [['']*(len(s1)+1) for _ in range(len(s2)+1)]
    for i in range(len(s2)+1):
        for j in range(len(s1)+1):
            if i == 0 or j == 0:
                dp[i][j] = ''
            else:
                if l1[j-1] == l2[i-1]:
                    dp[i][j] = dp[i-1][j-1] + l1[j-1]
                else:
                    if len(dp[i-1][j]) > len(dp[i][j-1]):
                        dp[i][j] = dp[i-1][j]
                    else:
                        dp[i][j] = dp[i][j-1]

    return dp[-1][-1]

ans = LCS()
print(len(ans))
print(ans)
```
<br>

### 결과
![image](https://user-images.githubusercontent.com/50696567/214482116-095ee3d4-735f-4854-ae19-642c3dabc12c.png)

<br>

### 풀이 방법
- `다이나믹 프로그래밍`을 활용하는 문제이다
- LCS 문제에서는 길이만 출력했다면 이 문제는 가장 긴 부분문자열도 출력하는 문제이다.
- LCS 알고리즘에서 dp 배열에 길이를 저장했던 것과 달리, 알고리즘은 동일한데 길이 대신 현재까지 가장 긴 부분문자열을 저장하면 된다.
- 알고리즘을 상기시키면 아래와 같다.
- 두 문자열 길이를 각각 n, m 이라고 가정했을 때, (n+1) x (m+1) 크기의 이차원 배열을 활용하여 `dp[i][j] = 문자열1의 i번째문자, 문자열2의 j번째문자 까지의 최대 부분문자열`로 나타낸다.
- `dp[i][j]에 대한 점화식`은 아래와 같다.
- 문자열1의 i번째 문자와 문자열2의 j번째 문자가 같은 경우, 이전까지(즉 각각의 문자열의 이전 글자까지)의 최대 부분문자열 dp[i-1][j-1]에 현재 문자를 더한다.
- 그렇지 않으면, 배열을 기준으로 위쪽(dp[i-1][j])과 왼쪽(dp[i][j-1]) 값 중 길이가 더 긴 문자열을 취하여 저장한다.
- 구하는 최종 값은 dp 배열의 가장 오른쪽 아래 값이다.
___
