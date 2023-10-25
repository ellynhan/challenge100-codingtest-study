import sys
import heapq # 힙
input=sys.stdin.readline # 입력 빠르게
n,k = map(int,input().split())
gems = [[*map(int,input().split())] for _ in range(n)]
bags = [int(input()) for _ in range(k)]
gems.sort() # 무게 오름차순, 무게 같으면 가격 오름차순
bags.sort() # 가방 무게 오름차순
result = 0 # 결과 출력값 초기화
tmp = [] # 보석의 가격 저장 리스트
 
for bag in bags: # 각 가방 무게에 대해
    while gems and gems[0][0] <= bag: #제일 가벼운 보석무게를 bag이 허용하는한 반복
        heapq.heappush(tmp, -gems[0][1]) # 가격을 최대힙에 저장(음수로 저장하여 최소힙을 최대힙으로)
        heapq.heappop(gems) # 가격 저장한 보석은 버리기
    if tmp: #bag 무게 이하 보석 가격 다 저장했으면
        result -= heapq.heappop(tmp) # 제일 가치가 높은 가격 더하기(음수니까 빼기)
print(result)