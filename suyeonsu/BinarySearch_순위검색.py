from itertools import combinations
from bisect import bisect_left, bisect_right

def solution(info, query):
    d = {}
    for i in info:
        k, score = i.split()[:-1], int(i.split()[-1])
        for n in range(5):
            for c in combinations(k, n):
                key = ''.join(c)
                if key not in d: d[key] = []
                d[key].append(score)
                
    answer = []
    for k in d.keys(): d[k].sort()
    for q in query:
        k = q.split()[:-1]
        score = int(q.split()[-1])
        key = ''.join([x for x in k if x not in['-', 'and']])
        if key in d:
            answer.append(len(d[key]) - bisect_left(d[key], score))
        else:
            answer.append(0)
    return answer
  
"""
탐색 알고리즘 종류: 선형, 이분, 해시, BST

원하는 값의 원소를 찾을 때 이분탐색을 잊지말자!!
+) 값이 x이 원소 개수, 값이 [a, b]에 속하는 원소 개수 찾을 때 등 활용 가능
"""
