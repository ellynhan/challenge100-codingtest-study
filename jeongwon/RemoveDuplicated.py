arr3 = list(map(int, input().split()))
s = set(arr3)
print('입력값: ', arr3)
print('출력값: ', sorted(s, reverse=True))

'''
# 도전과제
arr4 = list(map(int, input().split()))
print('입력 배열: ', arr4)

# 중복 제거
deduplicated = []
for i in range(len(arr4)):
    if arr4[i] not in deduplicated:
        deduplicated.append(arr4[i])

print('중복 제거: ', deduplicated)

# 정렬
for i in range(len(deduplicated) - 1): # 사이클 수
    for j in range(len(deduplicated) - i - 1):
        if deduplicated[j] < deduplicated[j+1]:
            temp = deduplicated[j+1]
            deduplicated[j+1] = deduplicated[j]
            deduplicated[j] = temp

print('정렬 결과: ', deduplicated)
'''
