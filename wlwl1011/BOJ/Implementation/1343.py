import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')


arr = ['AAAA','BB']

s = input()
cnt = 0
ans = ''

if s.count('X') == 0:
    print(-1)
else:
    for i in range(len(s)):
        
        if s[i] == '.':
            if cnt == 2:
                ans += 'BB' + '.'
            elif cnt >= 4 and cnt % 4 == 0:
                ans += 'A'*cnt + '.'
            elif (cnt % 4)%2 == 0:
                ans += (cnt//4)*'AAAA' + (cnt%4)*'B' + '.'
            else:
                print(-1)
                exit(0)
            cnt = 0
        else:
            cnt += 1    

    if cnt:
        if cnt == 2:
            ans += 'BB'
            print(ans)
        elif cnt >= 4 and cnt % 4 == 0:
            ans += 'A'*cnt
            print(ans)
        elif (cnt % 4)%2 == 0:
            ans += (cnt//4)*'AAAA' + (cnt%4)*'B'  
            print(ans)
        else:
            print(-1)

    else:
        print(ans)
