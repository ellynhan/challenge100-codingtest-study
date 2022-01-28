import sys
# from itertools import combinations

test_case_num = int(sys.stdin.readline())
for i in range(test_case_num) :
    n, m = map(int, sys.stdin.readline().split())
    if n > (m // 2) :
        n = m - n
    # combi_list = list(combinations(range(m), n))
    # print(len(combi_list))

    top = 1
    bot = 1
    for j in range(n) :
        top *= m
        m -= 1
    for k in range(n) :
        bot *= (k + 1)
    print(top//bot)
