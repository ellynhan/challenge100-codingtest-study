def solution(array, commands):
    answer = []
    for cmd in commands:
        tmp = array[cmd[0]-1:cmd[1]]
        tmp.sort()
        answer.append(tmp[cmd[2]-1])
    return answer
