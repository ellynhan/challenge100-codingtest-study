from heapq import heappop, heappush

expensive = 10**8

def make_graph(n, fares) :
    global graph
    graph = [[] for _ in range(n + 1)]
    for i in range(len(fares)) :
        graph[fares[i][0]].append([fares[i][1], fares[i][2]])
        graph[fares[i][1]].append([fares[i][0], fares[i][2]])
    return graph

def mindist(src, dst) :
    global graph
    dist = [expensive for i in range(len(graph))]
    dist[src] = 0
    heapq = [[0, src]]
    
    while heapq :
        total, x = heappop(heapq)
        
        if dist[x] < total :
            continue
        
        for i in range(len(graph[x])) :
            td, tx = graph[x][i][1], graph[x][i][0]
            td += total
            if td <= dist[tx] :
                dist[tx] = td
                heappush(heapq, [td, tx])   
                
    return dist[dst]

def solution(n, s, a, b, fares) :
    make_graph(n, fares)
    cost = expensive
    
    for i in range(1, n + 1) :
        cost = min(cost, mindist(s, i) + mindist(i, a) + mindist(i, b))

    return cost
