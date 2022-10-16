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
    dp = [[0]*(len(s1)+1) for _ in range(len(s2)+1)]
    for i in range(len(s2)+1):
        for j in range(len(s1)+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            else:
                if l1[j-1] == l2[i-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[-1][-1]

print(LCS())
```
<br>

### 결과
![image](https://user-images.githubusercontent.com/50696567/195764137-ce12d388-b576-4576-b1cd-9ff408d3414d.png)

<br>

### 풀이 방법
- `다이나믹 프로그래밍`을 활용하는 문제이다
- 두 문자열 길이를 각각 n, m 이라고 가정했을 때, (n+1) x (m+1) 크기의 이차원 배열을 활용하여 `dp[i][j] = 문자열1의 i번째문자, 문자열2의 j번째문자 까지의 최대 부분문자열 길이`로 나타낸다.
- `dp[i][j]에 대한 점화식`은 아래와 같다.
- 문자열1의 i번째 문자와 문자열2의 j번째 문자가 같은 경우, 이전까지(즉 각각의 문자열의 이전 글자까지)의 최대 부분문자열 길이인 dp[i-1][j-1]에 1을 더한 값을 저장한다.
- 그렇지 않으면, 배열을 기준으로 위쪽(dp[i-1][j])과 왼쪽(dp[i][j-1]) 값 중 큰 값을 취하여 저장한다.
- 구하는 최종 값은 dp 배열의 가장 오른쪽 아래 값이다.
___
