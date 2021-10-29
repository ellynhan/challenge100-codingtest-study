import sys

def fibonacci(state):
    initialState1 = [1, 0, 1]
    initialState2 = [0, 1, 1]
    stateLength = len(initialState1)
    if state >= stateLength:
        for i in range(stateLength, state+1):
            initialState1.append(initialState1[i-1] + initialState1[i-2])
            initialState2.append(initialState2[i-1] + initialState2[i-2])
    return f"{initialState1[state]} {initialState2[state]}"


if __name__ == "__main__":
    testLength = int(sys.stdin.readline())
    result = []
    for i in range(testLength):
        result.append(fibonacci(int(sys.stdin.readline())))
    for sol in result:
        print(sol)
#실버3 / 40분 
