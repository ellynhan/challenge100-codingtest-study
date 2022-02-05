#여행경로
#testcase1, 2번 실패 : 단순 dfs로 구현시 경로 끊어진 testcase 에러
from collections import defaultdict

def solution(tickets):
    dic = defaultdict(list)
    for ticket in tickets :
        dic[ticket[0]].append(ticket[1])

    for i in dic :
        dic[i].sort(reverse=True)

    # def dfs(x, path):
    #     # print(dic)
    #     path.append(x)
    #     if not dic[x]:
    #         return path
        
    #     else:
    #         arrival = dic[x].pop()
    #         # print(arrival)
    #         return dfs(arrival, path)

    # answer = dfs("ICN", answer)
    answer = []
    stack = ['ICN']
    while stack :
        tmp = stack[-1]
        if not dic[tmp]:
            answer.append(stack.pop())
        else:
            stack.append(dic[tmp].pop())
        print(stack)
        print(dic)
    answer.reverse()
    return answer

tickets= [["ICN", "A"], ["A", "B"], ["A", "C"], ["C", "A"], ["B","D"]]
dic = defaultdict(list)
dic["ICN"].append("QWE") 

print(solution(tickets))
