1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
import math

visited = []
nums = set()

def isprime(num : int):
    prime = True;
    for i in range(2,int(math.sqrt(num))+1):
        if num % i == 0:
            prime = False
            break;
    if num <= 1:
        prime = False
    return prime;



def dfs(depth, now, numStr) :
    global nums
    global visited
    if depth == len(numStr):
        if now != '':
            nums.add(int(now))
        return;
    for index, c in enumerate(numStr):
        if visited[index] == False:
            visited[index] = True
            dfs(depth+1, now+c,numStr)
            visited[index] = False
    dfs(depth+1, now ,numStr)
    return;
def solution(numbers):
    global visited
    global nums
    visited = [False for _ in range(len(numbers))]
    dfs(0,"",numbers)

    answer = 0
    print(nums)
    for i in nums:
        if isprime(i):
            answer += 1

    return answer