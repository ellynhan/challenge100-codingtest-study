# https://programmers.co.kr/learn/courses/30/lessons/43165

#스택 , dfs 풀이
import collections

def solution(numbers, target):
    answer = 0
    stack = collections.deque([(0, 0)])
    while stack:
        current_sum, num_idx = stack.pop()

        if num_idx == len(numbers):
            if current_sum == target:
                answer += 1
        else:
            number = numbers[num_idx]
            stack.append((current_sum+number, num_idx + 1))
            stack.append((current_sum-number, num_idx + 1))

    return answer

# 재귀, dfs 풀이
# count=0
# def solution(numbers, target):
#     num = [(x, -x) for x in numbers]
#     l = len(numbers)
#     def dfs(idx, buho, answer):
#         global count
#         if idx == l:
#             if answer == target:
#                 count+=1
#                 return
#             return
#         answer += num[idx][buho]
#         dfs(idx+1, 0, answer)
#         dfs(idx+1, 1, answer)
#     dfs(0,0,0)
#     dfs(0,1,0)
#     return count//2

# 내풀이 (이진수 활용) : 시간복잡도 너무 높음 ㅠ
# from collections import deque
# def solution(numbers, target):
#     l = len(numbers)
#     num = [numbers, [-x for x in numbers]]
#     for i in range(2**l):
#         tmp = 0
#         binary = (bin(i)[2:].zfill(l))
#         for idx, buho in enumerate(binary):
#             # print(idx, buho)
#             buho = int(buho)
#             tmp+=num[buho][idx]
#         if tmp == target:
#             answer+=1
#     return answer
