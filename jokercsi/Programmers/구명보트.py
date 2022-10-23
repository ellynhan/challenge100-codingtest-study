# 보트에는 두명만 들어감
# min 과 max 를 정하기
def solution(people, limit):
    stack = []
    count = 0
    people.sort(reverse=True)
    minKg = people.pop(len(people)-1)
    stack.append(minKg)
    
    for i, v in enumerate(people):
        if v + minKg <= limit:
            count += 1
            stack.clear()
            if i != len(people)-1:
                minKg = people.pop(len(people)-1)
                stack.append(minKg)
        else:
            count+= 1    
    
    if stack:
        count+=1
    
    return count
