import sys

if __name__ == "__main__":
    inputLine = list(map(int, sys.stdin.readline()[:-1].split()))
    queue = [i + 1 for i in range(inputLine[0])]
    remover = inputLine[1]

    result = []
    pointer = 0
    while(len(queue) != 0):
        pointer = (pointer + remover) % len(queue)
        if pointer == 0:
            pointer = len(queue)
        print(pointer)
        print(queue)
        result.append(queue[pointer-1])
        del queue[pointer-1]
        pointer = pointer - 1
        
    result = list(map(str, result))
    output = ", ".join(result)
    print(f"<{output}>")