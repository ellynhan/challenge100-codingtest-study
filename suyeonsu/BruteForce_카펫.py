def solution(brown, yellow):
    for n in range(1, int(yellow**(1/2))+1):
        if yellow % n == 0:
            w, h = yellow//n, n
            if (w + h) * 2 + 4 == brown:
                return [w+2, h+2]
