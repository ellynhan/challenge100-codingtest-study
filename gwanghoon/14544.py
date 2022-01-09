import sys

if __name__ == "__main__":
    numdatasets = int(sys.stdin.readline()[:-1])
    result = []
    for data in range(numdatasets):
        line = list(map(int, sys.stdin.readline()[:-1].split()))
        candidateList = dict()
        for i in range(line[0]):
            candidate = sys.stdin.readline()[:-1]
            candidateList[candidate] = 0

        for i in range(line[1]):
            vote = sys.stdin.readline()[:-1].split()
            candidateList[vote[0]] += int(vote[1])
        maximua = max(candidateList.values())
        winner = []
        for i in candidateList.keys():
            if candidateList[i] == maximua:
                winner.append(i)
        round = data + 1
        if len(winner) != 1:
            result.append(f"VOTE {round}: THERE IS A DILEMMA")
        else:
            result.append(f"VOTE {round}: THE WINNER IS {winner[0]} {maximua}")
    for lines in result:
        print(lines)


# 15분 변수 스코프 주의 또 주의