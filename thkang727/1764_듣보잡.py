#
#   1764
#   문자열
# #


n,m = map(int, input().split())
n_str=set()
ans=set()
for i in range(n):
    n_str.add(input())
for i in range(m):
    m_str=input()
    if m_str in n_str:
        ans.add(m_str)
ans = sorted(ans)
print(len(ans))
for i in ans:
    print(i)
