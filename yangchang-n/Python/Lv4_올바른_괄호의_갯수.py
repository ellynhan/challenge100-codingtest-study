def solution(n) :
    table = [0] * (n + 1)
    table[0], table[1] = 1, 1
    if n > 1 :
        for i in range(2, n + 1) :
            for j in range(i) :
                table[i] += table[j] * table[i - j - 1]
    return table[n]
