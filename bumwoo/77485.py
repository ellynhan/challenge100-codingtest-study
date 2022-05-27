def solution(rows, columns, queries):
    answer = [[] for _ in range(rows)]
    result = []
    k = 1
    for i in range(rows):
        for j in range(columns):
            answer[i].append(k)
            k += 1

    for q in queries:
        nums = []
        graph = []
        for i in range(len(answer)):
            graph.append(answer[i][:])
        # graph = copy.deepcopy(answer)로 할 경우 시간 초과.
        # 행 하나 리스트 마다 slicing 복사가 더 빠름.
        for i in range(q[1], q[3]):
            graph[q[0] - 1][i] = answer[q[0] - 1][i-1]
            nums.append(graph[q[0] - 1][i])
        for i in range(q[0], q[2]):
            graph[i][q[3] - 1] = answer[i-1][q[3] - 1]
            nums.append(graph[i][q[3] - 1])
        for i in range(q[3] - 2, q[1] - 2, -1):
            graph[q[2] - 1][i] = answer[q[2] - 1][i+1]
            nums.append(graph[q[2] - 1][i])
        for i in range(q[2] - 2, q[0] - 2, -1):
            graph[i][q[1] - 1] = answer[i+1][q[1] - 1]
            nums.append(graph[i][q[1] - 1])
        result.append(min(nums))
        answer = graph
    return result