from queue import deque

def diff_1(orig, comp) :
    diffcount = 0
    for k in range(len(orig)) :
        if orig[k] != comp[k] :
            diffcount += 1
        if diffcount > 1 : return False
    if diffcount == 0 : return False
    return True

def solution(begin, target, words) :
    if target not in words : return 0
    answer = 0
    count_que = deque()
    for word in words :
        if diff_1(begin, word) :
            count_que.append([word, 1])
    while True :
        check, count = count_que.popleft()
        if check == target :
            answer = count
            break
        for word in words :
            if diff_1(check, word) :
                count_que.append([word, count + 1])
    return answer
