n = int(input())
lh = [tuple(map(int, input().split())) for _ in range(n)]
lh.sort(key=lambda x:x[0])
max_h = 0
for l, h in lh:
    max_h = max(max_h, h)
max_l = [l for l, h in lh if h == max_h]

answer = (max_l[-1]-max_l[0]+1)*max_h
pre_l, pre_h = lh[0]
for cur_l, cur_h in lh[1:]:
    if pre_h < cur_h:
        answer += (cur_l-pre_l)*pre_h
        pre_l, pre_h = cur_l, cur_h
    if cur_h == max_h:
        break
pre_l, pre_h = lh[-1]
for cur_l, cur_h in lh[::-1]:
    if pre_h < cur_h:
        answer += (pre_l-cur_l)*pre_h
        pre_l, pre_h = cur_l, cur_h
    if cur_h == max_h:
        break
print(answer)

"""
최대 높이가 여러개인 경우를 조심하자
"""
