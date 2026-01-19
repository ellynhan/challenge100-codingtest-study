def solution(n, k, cmd):
    # 각 행의 [이전 행 인덱스, 다음 행 인덱스] 저장
    # 0번 행의 이전은 -1, 마지막 행의 다음은 -1로 처리
    linked_list = [[i - 1, i + 1] for i in range(n)]
    linked_list[0][0] = -1
    linked_list[n - 1][1] = -1 
    
    # 삭제된 행들을 담을 스택
    stack = []
    # 현재 선택된 행의 인덱스
    curr = k
    # 삭제 여부를 기록할 리스트 (최종 결과용)
    removed = [False] * n

    for c in cmd:
        if c.startswith('U'):
            # "U X": 위로 X칸 이동
            _, x = c.split()
            for _ in range(int(x)):
                curr = linked_list[curr][0]
                
        elif c.startswith('D'):
            # "D X": 아래로 X칸 이동
            _, x = c.split()
            for _ in range(int(x)):
                curr = linked_list[curr][1]
                
        elif c == 'C':
            # "C": 현재 선택된 행 삭제
            prev, nxt = linked_list[curr]
            stack.append([prev, curr, nxt])
            removed[curr] = True
            
            # 주변 노드의 연결 수정
            if prev != -1:
                linked_list[prev][1] = nxt
            if nxt != -1:
                linked_list[nxt][0] = prev
            
            # 다음 선택될 행 결정 (마지막 행이면 위로, 아니면 아래로)
            curr = nxt if nxt != -1 else prev
            
        elif c == 'Z':
            # "Z": 가장 최근 삭제된 행 복구
            r_prev, r_curr, r_nxt = stack.pop()
            removed[r_curr] = False
            
            # 주변 노드와 다시 연결
            if r_prev != -1:
                linked_list[r_prev][1] = r_curr
            if r_nxt != -1:
                linked_list[r_nxt][0] = r_curr
                
    # 최종 결과 문자열 생성
    result = []
    for i in range(n):
        result.append('X' if removed[i] else 'O')
        
    return "".join(result)
