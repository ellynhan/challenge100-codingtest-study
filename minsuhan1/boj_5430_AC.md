___
### 코드
```python
import sys
input = sys.stdin.readline

# 배열이 양방향이 뚫려있는 deque이라고 생각하고
# 'R'이 나올때마다 'D' 작업을 할 방향(좌, 우)을 바꾼다.
# 결과를 출력할 때는 현재 작업방향에 따라 앞에서부터 또는 뒤에서부터 출력한다.

for _ in range(int(input())):
    query = input().rstrip()
    strLen = int(input())
    arr = input()
    
    if strLen == 0:
        if 'D' in query:
            print('error')
            continue
        else:
            print('[]')
            continue
    else:        
        arr = list(map(int, arr[1:-2].split(',')))    # 괄호떼고 ',' 기준으로 split

    # 함수처리
    direction = 1    # 1: 왼쪽부터 처리, -1: 오른쪽부터 처리
    for i in range(len(query)):
        ch = query[i]
        
        if not arr:
            print('error')
            break
            
        if ch == 'D':
            if direction == 1:
                arr.pop(0)
            else:
                arr.pop(-1)
        if ch == 'R':
            direction *= -1

        if i == len(query)-1:
            if direction == 1:
                print('[' + ','.join(map(str, arr)) + ']')
            else:
                ans = []
                for i in range(len(arr)-1,-1,-1):
                    ans.append(arr[i])
                print('[' + ','.join(map(str, ans)) + ']')
```
<br>

### 결과
![image](https://user-images.githubusercontent.com/50696567/198516661-bf0bd67e-6612-4cf2-a01a-42ef48925d39.png)

<br>

### 풀이 방법
- 배열이 양방향이 뚫려있는 deque이라고 생각하고 'R'이 나올때마다 'D' 작업을 할 방향(좌, 우)을 바꾼다.
- 'D'일 때 현재 방향이 1이면 pop(0)을, -1이면 pop(-1)을 하고, 'R'일때는 방향 x= -1 계산을 하여 방향을 바꾼다.
- 결과를 출력할 때는 현재 작업방향에 따라 앞에서부터 또는 뒤에서부터 출력한다.
___
