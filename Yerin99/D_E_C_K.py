def shuffle():
    front = deck[:n//2]
    behind = deck[n//2:]
    for num in range(n):
        if num % 2 == 0:
            deck[num] = front[num//2]
        else:
            deck[num] = behind[num//2]


def cut(a, b):
    return deck[:a-1] + deck[b:] + deck[a-1:b]


n, k = map(int, input().split())
deck = list(range(1, n+1))

for _ in range(1, k+1):
    order = input().split()
    if order[0] == "Shuffle":
        shuffle()
    elif order[0] == "Cut":
        i, j = int(order[1]), int(order[2])
        deck = cut(i, j)

print(deck[0], deck[n//2-1], deck[-1])
