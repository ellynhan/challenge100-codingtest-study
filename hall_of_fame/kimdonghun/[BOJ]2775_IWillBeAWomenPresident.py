import sys
import math

T = int(sys.stdin.readline())

for i in range(T) :
    K = int(sys.stdin.readline())
    N = int(sys.stdin.readline())

    m_list = [0] * (N+1)

    for l in range(N+1) :
            m_list[l] = l

    for j in range(K) :
        for l in range(1, N+1) :
            m_list[l] = m_list[l] + m_list[l-1]

    #print(m_list)

    print(m_list[N])
    
        

    