# H- Index

def solution(citations):
    citations.sort()
    citations.reverse()
    
    for i in range(len(citations), 0, -1):
        if (citations[i-1] >= i):
            return i
    return 0

# # 다른사람 풀이
# def solution(citations):
#     citations.sort(reverse=True)
#     answer = max(map(min, enumerate(citations, start=1)))
#     return answer

print(solution([0, 5, 7, 9]))
