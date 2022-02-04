from collections import defaultdict
def solution(answers):
    pattern = [[],[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]]
    
    correct = defaultdict(int)
    for i in range(len(answers)):
        if pattern[1][i % 5] == answers[i]:
            correct[1] += 1
        if pattern[2][i % 8] == answers[i]:
            correct[2] += 1
        if pattern[3][i % 10] == answers[i]:
            correct[3] += 1
    correct = sorted(correct.items(), key = lambda x: x[1],reverse = True)
    # print(correct)
    answer = [x[0] for x in correct if x[1] == correct[0][1]]

    return sorted(answer)