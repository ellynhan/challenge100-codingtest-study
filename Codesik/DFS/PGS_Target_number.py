# 5:55 6:07 종료 총 12분걸림
answer = 0


def dfs(number, index, target, numbers):
    global answer
    if index == len(numbers) - 1:
        if number == target:
            answer += 1
        return

    dfs(number + numbers[index + 1], index + 1, target, numbers)
    dfs(number - numbers[index + 1], index + 1, target, numbers)


def solution(numbers, target):
    global answer
    dfs(-numbers[0], 0, target, numbers)
    dfs(numbers[0], 0, target, numbers)
    return answer