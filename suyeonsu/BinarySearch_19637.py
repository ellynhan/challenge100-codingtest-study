from bisect import bisect_left
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
label = []
val = []
for _ in range(n):
    a, b = input().split()
    label.append(a)
    val.append(int(b))

for _ in range(m):
    v = int(input())
    print(label[bisect_left(val, v)])
    
"""
이분탐색 라이브러리를 쓰자 

- bisect(iterable, value)
  이터러블한 객체, 찾는 값을 입력하면 그 값의 인덱스를 반환
  (값이 없을때는 insert해도 정렬이 안깨질 것 같은 가장 오른쪽 인덱스를 반환) -> bisect_right()와 동일
  
- bisect_left(iterable, value)
  이터러블한 객체, 찾는 값을 입력하면 왼쪽에서부터 세어서 그 값의 인덱스를 반환
  이상, 초과, 미만을 구현하기 좋음
  (값이 없을때는 insert해도 정렬이 안깨질 것 같은 가장 왼쪽 인덱스를 반환)
"""
