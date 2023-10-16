from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]
def rotate_melt(arr, arr_len, l):
    copy_arr = [a[:] for a in arr]

    l_size = 2**l

    for x in range(0,arr_len,l_size):
        for y in range(0, arr_len, l_size):
            for i in range(l_size):
                for j in range(l_size):
                    arr[x+j][y+l_size-1-i]=copy_arr[x+i][y+j]
    remove = []
    for x in range(arr_len):
        for y in range(arr_len):
            cnt = 0
            for i in range(4):
                tx = x + dx[i]
                ty = y + dy[i]
                if 0 <= tx < arr_len and 0 <= ty < arr_len:
                    if arr[tx][ty]:
                        cnt += 1
            if cnt <= 2:
                remove.append((x,y))

    for x,y in remove:
        if arr[x][y]:
            arr[x][y] -= 1

    return arr

def count_ice(arr,len_arr):
    answer = 0
    visited = [[0 for _ in range(len_arr)] for _ in range(len_arr)]
    for x in range(len_arr):
        for y in range(len_arr):
            if visited[x][y] or arr[x][y] == 0:
                continue
            cnt = 1
            queue = deque()
            queue.append((x,y))
            visited[x][y] = 1
            while queue:
                r, c = queue.popleft()

                for i in range(4):
                    tr = r + dx[i]
                    tc = c + dy[i]
                    if not visited[tr][tc] and arr[tr][tc]:
                        cnt += 1
                        visited[tr][tc] = 1
                        queue.append((tr,tc))
            answer = max(answer,cnt)

    return answer



def solve():
    N, Q = map(int, input().split())
    arr = []
    for _ in range(2**N):
        arr.append(list(map(int, input().split())))
    L = list(map(int, input().split()))

    for l in L:
        arr = rotate_melt(arr,2**N,l)
    total_sum = 0
    for i in range(2**N):
        total_sum += sum(arr[i])
    print(total_sum)
    print(count_ice(arr, 2**N))


if __name__ == '__main__':
    solve()
