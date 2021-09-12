#90도 회전
def rotate_arr(arr):
  r_arr = [[0]*len(arr) for _ in range(len(arr))]
  for j in range(len(arr)):
    for i in range(len(arr)):
      r_arr[j][len(arr)-i-1] = arr[i][j] #0열이 0행으로, reverse 삽입
  return r_arr

#arr이동
def move_arr(arr,move_col,move_row,len_k,set_len,st_pnt):
  m_arr = [[0]*set_len for _ in range(set_len)]
  for i in range(st_pnt,st_pnt+len_k):
    for j in range(st_pnt,st_pnt+len_k):
      m_arr[i+move_col][j+move_row] = arr[i][j]
  return m_arr

#key와 lock 맞춰보기.
def Open(key,lock,len_l,st_pnt):
  for i in range(st_pnt,st_pnt+len_l):
    for j in range(st_pnt,st_pnt+len_l):
      if key[i][j]+lock[i][j] != 1:
        return False
  return True


def solution(key, lock):
    answer = True
    length_k = len(key)
    length_l = len(lock)
    #확장시킬 배열의 크기.
    set_len = (len(lock)-1)*3+1 #out range of 가 발생하지 않을만큼만 선언
    st_pnt = len(lock)-1 #key와 lock이 확장된 배열에 삽입될 시작점.
    
    #확장시킨 배열에 key와 lock 삽입
    ex_key = [[0]*set_len for _ in range(set_len)]
    ex_lock = [[0]*set_len for _ in range(set_len)]    
    for i in range(length_k): 
      for j in range(length_k):
        ex_key[st_pnt+i][st_pnt+j] = key[i][j]
    for i in range(length_l):
      for j in range(length_l):
        ex_lock[st_pnt+i][st_pnt+j] = lock[i][j]

    #col, row : 탐색시킬 행과 열의 범위설정 = key를 이동시킬 범위.
    col = -(length_k-1)
    row = length_l-1
    for _ in range(4): #90도 씩 rotate하며 탐색
      for c in range(col,row+1):
        for r in range(col,row+1):
          move_ex_key = move_arr(ex_key,c,r,length_k,set_len,st_pnt)
          if Open(move_ex_key, ex_lock,length_l,st_pnt):
            return answer
      
      #key 회전 시킨 후 확장 배열에 다시 삽입.
      key = rotate_arr(key)
      for x in range(length_k):
        for y in range(length_k):
          ex_key[st_pnt+x][st_pnt+y] = key[x][y]

    answer = False
    return answer

print(solution([[0,0,0],[1,0,0],[0,1,1]], [[1,1,1],[1,1,0],[1,0,1]]))
