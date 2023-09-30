def testPerformance(A):			# 필름 성능 검사
    for c in range(W):
        cnt = 1
        for r in range(1, D):
            if A[r][c] == A[r-1][c]:
                cnt += 1
            else:
                cnt = 1
            if cnt >= K:        # 동일 특성이 K개 이상이면 break하고 다음 열 검사
                break
        if cnt < K:             # 해당 열에서 동일 특성이 K 미만이면 불합격
            return False
    return True                 # 모두 통과하면 합격

def comb(depth, k, pick):		# DFS 조합 구현
    global result
    if depth >= result:         # 최소 약품 주입 횟수보다 크거나 같으면 가지치기
        return
        
    if depth == pick:           # pick 횟수에 도달했다면 검사 후 갱신
        if testPerformance(film):
            result = min(result, depth)
        return
        
    for i in range(k, D):				# 막 선택
        for d in range(2):				# A 약품 or B 약품 둘 중 하나 선택
            select.append(i)
            film[i] = drugs[d]          # 약품 투입
            comb(depth+1, i+1, pick)
            film[i] = raw[i]            # 복원
            select.pop()

# main
T = int(input())
for tc in range(T):
    D, W, K = map(int, input().split())
    film = [list(map(int, input().split())) for _ in range(D)]
    raw = [f[:] for f in film]
    drugs = [[0] * W, [1] * W]

    if testPerformance(film):   # 원래의 필름으로 한 번에 성능 검사 통과
        result = 0
    else:                       # 한 번에 통과하지 못함 => 약물 투입
        result = float('inf')
        select = []
        for pick in range(1, D+1):
            comb(0, 0, pick)
            if result < float('inf'):   # 갱신된 적 있으면 break
                break

    print("#{} {}".format(tc+1, result))
