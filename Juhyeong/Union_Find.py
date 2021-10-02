#서로소 집합 자료구조를 union-find 자료구조라 부르기도 한다.
#의미가 모호하다고 느껴진다. 서로소 집합은 공통원소가 없는 두 집합을 의미하고
#union_find는 합치기 연산과 찾기연산을 말하는 것이지 않나? 조금 더 와닿는 설명이 필요할것같다.
def find_parent(parent, x):
  if parent[x] != x:
    parent[x] = find_parent(parent, parent[x])
  
  return parent[x]
#루트노드를 찾음으로써 어떤 집합에 속하는지 찾기.

def union_parent(parent, a, b):
  a = find_parent(parent, a)
  b = find_parent(parent, b)
  if a<b:
    parent[b] = a
  else:
    parent[a] = b
# 두 노드의 루트노드를 찾아서 합쳐줌으로써 두 노드를 하나의 집합으로 만들기.

v,e= map(int, input().split())
parent = [0]*(v+1)

for i in range(1, v+1):
  parent[i] = i

for i in range(e):
  a,b = map(int, input().split())
  union_parent(parent,a,b)

print('각 원소가 속한 집합: ', end = '')
for i in range(1, v+1):
  print(find_parent(parent,i), end='')

print()

print('부모 테이블: ', end='')
for i in range(1, v+1):
  print(parent[i], end='')