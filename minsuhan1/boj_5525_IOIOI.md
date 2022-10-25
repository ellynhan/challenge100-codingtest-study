___
### 코드
```python
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = input()

ans, i, cnt = 0, 0, 0

while i < m-1:
    if s[i:i+3] == 'IOI':
        cnt += 1
        if cnt == n:
            ans += 1
            cnt -= 1
        i += 2
    else:
        cnt = 0
        i += 1

print(ans)
```
<br>

### 결과
![image](https://user-images.githubusercontent.com/50696567/197684429-a6f41705-7a16-49a9-9b7a-aaa49515b396.png)

<br>

### 풀이 방법
- `문자열`, `슬라이싱` 관련 문제이다
- 서브태스크 1은 문자열에서 현재 문자를 기준으로 뒤의 2n+1글자가 Pn과 같은지 확인하는 것(시간복잡도 O(n^2))만으로도 해결할 수 있다.
- 하지만 서브태스크 2는 문자열이 길기 때문에 O(n) 또는 O(nlogn)정도의 시간복잡도를 갖는 알고리즘을 설계해야한다.
- 현재 문자를 기준으로 3글자가 'IOI'이면 cnt를 증가시킨다. 그리고 다음 글자는 건너뛰고 그 다음 문자부터 또 3글자가 'IOI'이면 cnt를 증가시킨다.
- 이 과정을 반복하다가 cnt == n 이 되면 지금까지 카운트하면서 본 문자열이 0이 n개인 Pn 문자열이라는 뜻이므로 ans를 증가시킨다. 그리고 다음 반복에서 또 'IOI'가 나와서 Pn이 될 수 있으므로 cnt를 1만큼 감소시킨다.
- 현재 문자를 기준으로 3글자가 'IOI'가 아니면 cnt를 0으로 초기화하고 다음 인덱스부터 다시 검색한다.
___
