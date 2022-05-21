#https://programmers.co.kr/learn/courses/30/lessons/17681
def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        tmp = str(bin(arr1[i]|arr2[i])[2:].zfill(n))
        tmp = tmp.replace('1', '#')
        tmp = tmp.replace('0', ' ')
        answer.append(tmp)
    
    return answer

#너무 바보같이 풀었다 집중!
# def solution(n, arr1, arr2):
#     answer = []
#     arr3 = [[],[]]
#     for i in range(n):
#         arr3[0].append(bin(arr1[i])[2:].zfill(n))
#     for i in range(n):
#         arr3[1].append(bin(arr2[i])[2:].zfill(n))

#     for i in range(n):
#         tmp = ''
#         for j in range(n):
#             if arr3[0][i][j] == '1' or arr3[1][i][j] == '1':
#                 tmp+='#'
#             else:
#                 tmp+=' '
#         answer.append(tmp)
#     # print(arr3)

#     return answer