#섬 연결하기 (kruskal algorithm)
#1트 : 묶인 섬들간 연결이 안되어(ex. 1-2-3, 4-5) 실패
#2트 : 연결된것들 하나씩 늘려나간단 생각으로 성공

def solution(n, costs):
    costs.sort(key = lambda x:x[2])
    check = set([costs[0][0]])
    # print(check)
    answer = 0
    while len(check)!=n:
        for i in range(len(costs)):
            if (costs[i][0] in check) and (costs[i][1] in check):
                continue
            if (costs[i][0] in check) or (costs[i][1] in check):
                answer += costs[i][2]
                check.add(costs[i][0])
                check.add(costs[i][1])
                costs[i] = [-1,-1,-1]
                # print(check)
                break #이거 없으면 len(check) 확인을 못하고 계속 늘어남

    return answer

costs = [[0, 1, 1], [3, 4, 1], [1, 2, 2], [2, 3, 4]]
n = 5
print(solution(n, costs))
