import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')
#Month, Day, Year, Hour, Minute 

s = list(input().split())

if s[0] == 'January':
    Month = 1
elif s[0] == 'February':
    Month = 2
elif s[0] == 'March':
    Month = 3
elif s[0] == 'April':
    Month = 4    
elif s[0] == 'May':
    Month = 5
elif s[0] == 'June':
    Month = 6   
elif s[0] == 'July':
    Month = 7
elif s[0] == 'August':
    Month = 8
elif s[0] == 'September':
    Month = 9
elif s[0] == 'October':
    Month = 10
elif s[0] == 'November':
    Month = 11         
elif s[0] == 'December':
    Month = 12                  


Day = int(s[1].replace(',',''))
Year = int(s[2])
Hour, Minute = map(int, s[3].split(':'))


if (Year % 400 == 0) or (Year % 4 == 0 and Year % 100): #윤년
    m = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total = sum(m) * 24 * 60

    t = ( sum(m[:Month-1]) + Day-1 ) * 24 * 60 +  (Hour*60) + Minute

    print(t/total*100)

else:
    m = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    total = sum(m) * 24 * 60

    t = ( sum(m[:Month-1]) + Day-1 ) * 24 * 60 +  (Hour*60) + Minute

    print(t/total*100)