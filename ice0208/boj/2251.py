import sys
from collections import deque

input = sys.stdin.readline


def move(origin_data: tuple, fr_idx, to_idx):
    data = list(origin_data[:])
    to_remain = MAX[to_idx] - data[to_idx]
    move_amount = min(to_remain, data[fr_idx])

    data[fr_idx] -= move_amount
    data[to_idx] += move_amount

    return tuple(data)


if __name__ == "__main__":
    MAX = tuple(map(int, input().split()))

    results = set()
    visit = set()

    queue = deque()
    queue.append((0, 0, MAX[2]))
    visit.add((0, 0, MAX[2]))

    while queue:
        cur_data = queue.popleft()

        if cur_data[0] == 0:
            results.add(cur_data[2])

        for i in range(3):
            for j in range(3):
                if i == j:
                    continue
                next_status = move(cur_data, i, j)

                if next_status in visit:
                    continue
                visit.add(next_status)
                queue.append(next_status)

    print(*sorted(results))
