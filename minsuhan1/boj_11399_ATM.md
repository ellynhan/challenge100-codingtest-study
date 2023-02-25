___
### 코드
```python
import sys
input = sys.stdin.readline

N = int(input())
p = list(map(int, input().split()))

p.sort()

ans = 0
wait = 0
for num in p:
    wait += num
    ans += wait
    
print(ans)
```
<br>

### 결과
![image](https://user-images.githubusercontent.com/50696567/191637494-b1d68888-79b1-4ce3-ab72-dd563bf80f22.png)

<br>

### 풀이 방법
- 대기시간이 짧은 사람이 먼저 ATM을 사용해야 전체 사람들의 대기시간 합이 최소가 된다
- 따라서 입력받은 대기시간을 오름차순 정렬한 다음 대기시간 합을 구하면 된다
___
