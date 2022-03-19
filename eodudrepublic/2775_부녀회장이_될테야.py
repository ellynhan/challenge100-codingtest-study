import sys

def build() :
    apartment = []
    for i in range(15) :
        if i == 0 :
            apartment.append(list(range(1, 15)))
        else :
            apartment.append([1])
            for j in range(1, 14) :
                apartment[i].append(apartment[i][j-1] + apartment[i-1][j])
    return apartment

apartment = build()
test_case_num = int(sys.stdin.readline())
for i in range(test_case_num) :
    k = int(sys.stdin.readline())   # k층
    n = int(sys.stdin.readline())   # n호
    print(apartment[k][n-1])
