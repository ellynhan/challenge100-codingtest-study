#노드와 간선 입력 받음.
#각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트 만들기
#정보가 1,2,2 1,3,2 이런식으로 주어진다. 1번 노드와 연결되어있는 2,3번노드와 각 간선 크기다.
#입력 수가 많아서 빠르게 받기 위해 sys.stdin.readLine 을 쓴다.


import sys
INF = int(1e9)
input = sys.stdin.readline

n,m = map(int, input().split())
start = int(input())

graph = [[] for i in range(n+1)] #빈공간 2차원 배열 선언. graph[1]은 1층 탐색가능..
visited = [0]*(n+1)
distance = [INF]*(n+1)

for _ in range(m):
  a,b,c = map(int, input().split())
  graph[a].append((b,c))

def get_smallest_node():
  min_value = INF
  index = 0
  for i in range(1, n+1):
    if distance[i] < min_value and not visited[i]:
      min_value = distance[i]
      index = i
  return index


def dijkstra(start):
  visited[start] = 1
  distance[start] = 0

  for j in graph[start]:
    distance[j[0]] = j[1]

  for i in range(n-1):
    now = get_smallest_node()
    visited[now] = True
    for j in graph[now]:
      cost = distance[now] + j[1]
      if cost < distance[j[0]]:
        distance[j[0]] = cost


dijkstra(start)

for i in range(1,n+1):
  if distance[i] == INF:
    print("INFINITY")
  else:
    print(distance[i])
