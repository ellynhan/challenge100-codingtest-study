"""
자신보다 뒤에서 크면서 가장 가까운 수 
"""
def solution(numbers):
    answer = [-1 for i in range(len(numbers))]
    stack = []
    
    for i in range(len(numbers)):
            while stack and numbers[stack[-1]] < numbers[i]:
                answer[stack.pop()] = numbers[i]
            stack.append(i)

    return answer
