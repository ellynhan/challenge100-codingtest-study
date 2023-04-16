'''
==============================================================================================
@ Title: 속타는 저녁 메뉴
@ URL: https://www.acmicpc.net/problem/11585
@ Author: jopemachine
@ Created Date: 4/15/2023, 7:29:05 PM
@ Tags: kmp string
@ Level: Platinum 5
@ Description:
수원이와 친구들은 저녁 메뉴를 잘 선택하지 못한다. 배가 고픈 수원이가 보다 못해 메뉴를 정하곤 하는데 이마저도 반대에 부딪히는
경우에는 수원이가 원형 룰렛을 돌려 결정하곤 한다. 이 원형 룰렛으로 메뉴를 선택하는 방법은 매우 독특한데, 원형 룰렛을 돌린 뒤
12시부터 시계방향으로 읽어서 나오는 모양으로 저녁 메뉴를 결정한다. 원형 룰렛에는 정확히 N개로 나누어진 칸이 존재하고, 각 칸에는
알파벳 대문자 하나가 써져있다. 또한 원형 룰렛의 12시 방향에 존재하는 화살표는 칸 사이에 걸치는 일이 없이 항상 하나의 특정한 칸을
가리키게 되며, 원형 룰렛을 돌렸을 때, N개의 칸이 12시에 존재하게 될 확률은 모두 같다. 오늘도 저녁 메뉴를 고르지 못한 수원이와
친구들은 고기를 먹자는 수원이의 의견을 반대하여 결국 원형 룰렛을 돌리게 되었다. 원형 룰렛을 돌려 수원이가 오늘 고기를 먹게 될
확률을 계산하는 프로그램을 작성하자.
@ Input: 첫 번째 줄에는 원형 룰렛의 칸 수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 두 번째 줄에는 저녁 메뉴로 고기를 선택하게 되는
원형 룰렛의 모양이 12시 방향부터 시계방향으로 공백을 구분으로 한 글자씩 N개 주어진다. 세 번째 줄에는 현재의 원형 룰렛 모양이
12시 방향으로부터 시계방향으로 공백을 구분으로 한 글자씩 N개 주어진다.
@ Output: 원형 룰렛을 돌렸을 때 오늘 저녁으로 고기를 선택하게 되는 확률을 기약분수 형태로 출력한다. 기약분수란 분자와 분모가 더 이상 약분이
안 되는 형태를 의미한다. 만약 룰렛이 어떤 곳에 멈춰도 고기를 먹을 수 있다면 1/1 을 출력한다. 원형 룰렛을 돌려 고기를 먹을 수
있는 경우의 수는 적어도 한 가지 이상 있기 때문에 분자가 0이 되는 경우는 없다.
==============================================================================================
'''


def get_partial_table(s):
    pi = [0] * len(s)
    begin, matched = 1, 0
    while begin + matched < len(s):
        if s[begin + matched] == s[matched]:
            matched += 1
            pi[begin + matched - 1] = matched
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - pi[matched - 1]
                matched = pi[matched - 1]
    return pi


def kmp(h, n):
    ans = []
    begin, matched = 0, 0
    pi = get_partial_table(n)

    while begin <= len(h) - len(n):
        if matched < len(n) and h[begin + matched] == n[matched]:
            matched += 1
            if matched == len(n):
                ans.append(begin)
        else:
            if matched == 0:
                begin += 1
            else:
                begin += matched - pi[matched - 1]
                matched = pi[matched - 1]
    return ans


N = int(input())
want = input().split()
curr = input().split()

cnt = len(kmp(curr + curr[:-1], want))

if N % cnt == 0:
    N = N // cnt

print(f"1/{N}")
