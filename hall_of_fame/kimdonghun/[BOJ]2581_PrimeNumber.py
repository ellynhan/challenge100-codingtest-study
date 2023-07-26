import sys

M = int(sys.stdin.readline())
N = int(sys.stdin.readline())

psum = 0
pmin = 0

plist = []

for i in range(M, N+1) :
    cur_num = i
    cur_div_cnt = 0

    if cur_num > 1 :
        for j in range(2,  cur_num) :
            if cur_num % j == 0 :
                cur_div_cnt += 1
                break

        if cur_div_cnt == 0 :
            #plist.append(cur_num)
        
            if psum == 0 :
                pmin = cur_num

            psum += cur_num
        

if psum > 0 :
    print(psum)
    print(pmin)
    '''
    print(sum(plist))
    print(min(plist))
    '''
else :
    print(-1)