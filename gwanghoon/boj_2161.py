"""브론즈2 2161"""

def action(state, trash):
    x = state.pop(0)
    trash.append(x)
    y = state.pop(0)
    state.append(y)

def deck(size):
    state = [str(i) for i in range(1,size+1)]
    trash = []

    while (len(state) != 1):
        action(state,trash)
    trash.append(state[0])

    return trash

if __name__ == "__main__":
    deck_size = int(input())
    result = deck(deck_size)
    print(" ".join(result))

"9분 12초"

