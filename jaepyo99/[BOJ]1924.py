x,y=map(int,input().split())
day=['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT','SUN']
summ=0
for m in range(1,x):
    if(m==2):
        summ+=28        
    elif(m in [1,3,5,7,8,10,12]):
        summ+=31
    else:
        summ+=30
summ+=y

print(day[(summ%7)-1])
