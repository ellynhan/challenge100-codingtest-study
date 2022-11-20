def solution(s):
    answer = []
    stack = []
    
    s = s[1:-1]
    
    for i in s:
        if i == '{':
            continue
        elif i == '}':
            stack = list(map(int, stack)) # 리스트의 모든 string 요소를 int로 바꾸는 코드
            answer.append(stack)
            stack = []
        else:
            if not stack and i != ',':
                stack.append(i)
            elif i == ',':
                stack.append('')
            else:
                stack[-1] += i

    n = len(answer)
    
    li = [[] for i in range(n)] # 리스트의 길이 미리 정하기

    for i in answer:
        li[len(i)-1] = i
        
    realAnswer = []
    
    for i in li:
        for j in i:
            if not j in realAnswer:
                realAnswer.append(j)
    
    return realAnswer
