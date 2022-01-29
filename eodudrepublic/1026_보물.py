import sys
import copy

# 소요시간 5분
# 문제의 조건을 신경안쓰고 출력값만 올바르게 나오는 함수
# def function_S1(a, b) :
#     a.sort()
#     a.reverse()
#     b.sort()

# 소요시간 1시간
# 예제는 다 맞는데 계속 오답이 나와서 한참을 해매다, temp_index = sorted_b.index(temp)을 이용하면 b에 중복된 요소가 올 경우 잘못된 값이 입력되는 경우가 있음을 발견하고 해결할 수 있었습니다.
# 요약 : 위에 방식으로 너무 쉽게 풀고 방심하다 삽질함
# 함수에서 리스트를 복사할땐 copy 모듈의 copy.deepcopy()을 이용해야 하는걸 기억하자
def function_S2(a, b, n) :
    return_a = []
    sorted_b = copy.deepcopy(b)
    a.sort()
    a.reverse()
    sorted_b.sort()
    for i in range(n) :
        temp = b[i]
        temp_index = sorted_b.index(temp)
        return_a.append(a[temp_index])
        sorted_b[temp_index] = -1
    return return_a


result_S = 0
num_N = int(sys.stdin.readline())
list_A = list(map(int, sys.stdin.readline().split()))
list_B = list(map(int, sys.stdin.readline().split()))

# function_S1(list_A, list_B)
list_A = function_S2(list_A, list_B, num_N)


for i in range(num_N) :
    result_S = result_S + (list_A[i] * list_B[i])
print(result_S)
