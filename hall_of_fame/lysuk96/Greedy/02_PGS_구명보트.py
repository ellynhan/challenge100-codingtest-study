# 구명보트
# 1트 : 시간초과, 뒤에 사람들 다 del하면서 count할것!
# 2트 : 효율성 1번 시간초과, del하면서 해서 그런듯?

def solution(people, limit):
    people.sort()
    print(people)

    count = 0

    left = 0
    right = len(people)-1
    while left < right :
        while people[left] + people[right] >limit:
            if left == right:
                break
            count +=1
            right -= 1
        print(left, right)
        right -=1
        left+=1
        count +=1
            
    return count

print(solution([20, 30, 50, 50, 70, 80, 80], 100))
