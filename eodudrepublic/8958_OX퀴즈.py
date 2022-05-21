import sys

test_case_num = int(sys.stdin.readline())

for i in range(test_case_num) :
    ex_result = "X"
    total_score = 0
    score = 0
    test_case = list(sys.stdin.readline().strip())
    for result in test_case :
        if result == "X" :
            score = 0
            ex_result = "X"
        else :
            if ex_result == "O" :
                score += 1
            else :
                score = 1
                ex_result = "O"
            total_score += score
            
    print(total_score)
