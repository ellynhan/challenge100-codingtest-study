from collections import deque


def solution(numbers, target):
    count = 0
    queue = deque([(0, 0)])
    while queue:
        cur_sum, index = queue.popleft()

        if index == len(numbers):
            if cur_sum == target:
                count += 1
        else:
            cur_num = numbers[index]
            queue.append(((cur_sum + cur_num), index + 1))
            queue.append(((cur_sum - cur_num), index + 1))

    return count

