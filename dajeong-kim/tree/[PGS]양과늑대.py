from collections import deque
def solution(info, edges):
    def build_tree(info, edges):
        tree = [[] for _ in range(len(info))]
        for edge in edges:
            tree[edge[0]].append(edge[1])
        return tree

    # 트리 생성
    tree = build_tree(info, edges)
    
    max_sheep = 0
    
    # 현재위치, 양의수, 늑대의수, 방문노드 set()
    q = deque([(0, 1, 0, set())])
    
    while q:
        cur, sheep, wolf, visited = q.popleft()
        
        max_sheep = max(sheep, max_sheep)
        
        # 현재 노드의 이웃 노드 추가
        visited.update(tree[cur])
        
        for next_node in visited:
            # 늑대일 경우
            if info[next_node] == 1:
                if (sheep - wolf) != 1:
                    q.append((next_node, sheep, wolf+1, visited - {next_node}))
            # 양일 경우
            else:
                q.append((next_node, sheep+1, wolf, visited-{next_node}))
    
    return max_sheep 
                