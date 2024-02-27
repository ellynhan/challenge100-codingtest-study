def solution(A,B):
    answer = 0
    A=sorted(A)
    B=sorted(B)
    size=len(A)
    for i in range(size):
        print(A[i]*B[size-i-1])
        answer+=A[i]*B[size-i-1]

    return answer
