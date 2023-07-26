# 단어 변환
# 최소 거리 == bfs 임을 명시
from collections import defaultdict, deque

def solution(begin, target, words):
    def compare(x,y):
        count = 0
        for i in range(len(x)):
            if x[i] != y[i]:
                count+=1
        if count == 1:
            return True
        return False

    dic = defaultdict(list)

    for word in words:
        if compare(begin, word):
            dic[begin].append(word)

    for i in range(len(words)-1):
        for j in range(i+1,len(words)):
            if compare(words[i], words[j]):
                dic[words[i]].append(words[j])
                dic[words[j]].append(words[i])
    
    # print(dic)

    q = deque([begin])
    path = [begin]

    depth = defaultdict(int)
    depth[begin] = 0
    while q:
        print(q)
        tmp = q.popleft()
        if tmp == target:
            return depth[tmp]
        for node in dic[tmp]:
            if node not in path:
                depth[node] = depth[tmp]+1
                q.append(node)
                path.append(node)
    return 0
            

print(solution("hit",	"cog",	["hot", "dot", "dog", "lot", "log", "cog"]))
