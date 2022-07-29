import sys

N, M = map(int, sys.stdin.readline().split())

no_listen = set()
for i in range(N) :
    name = sys.stdin.readline().strip()
    no_listen.add(name)

no_hear = set()
for i in range(M) :
    name = sys.stdin.readline().strip()
    no_hear.add(name)

nor_listen_hear = no_listen & no_hear
print(len(nor_listen_hear))
nor_list = list(nor_listen_hear)
nor_list.sort()
for name in nor_list :
    print(name)

