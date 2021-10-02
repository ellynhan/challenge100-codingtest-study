#특정 원소가 속한 집합을 찾기
def find_parent(parent,x):
  #루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
  if parent[x] != x:
    parent[x] = find_parent(parent, parent[x])
  
  return parent[x]

#두 원소가 속한 집합을 합치기
def union_parent(parent,a,b):
  a = find_parent(parent,a)
  b = find_parent(parent,b)

  if a<b:
    parent[b] = a
  else:
    parent[a] = b

n ,m = map(int, input().split())

#노드들의 부모 테이블 초기화
parent = [0]*(n+1)
for i in range(1,n+1):
  parent[i] = i

answer_list = []

# question이 0일 경우, 두 학생을 같은 팀으로 합치기(union))
# question이 1일 경우, 두 학생이 같은 팀인지 확인하기(find)
for _ in range(m):
  question, a, b = map(int, input().split())
  if question == 0:
    union_parent(parent, a, b)
  else:
    if find_parent(parent,a) == find_parent(parent, b):
      answer_list.append('YES')
    else:
      answer_list.append('NO')

for i in answer_list:
  print(i)


