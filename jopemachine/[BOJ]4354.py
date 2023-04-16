'''
==============================================================================================
@ Title: 문자열 제곱
@ URL: https://www.acmicpc.net/problem/4354
@ Author: jopemachine
@ Created Date: 4/16/2023, 9:52:15 AM
@ Tags: kmp string
@ Level: Platinum 5
@ Description:
알파벳 소문자로 이루어진 두 문자열 a와 b가 주어졌을 때, a*b는 두 문자열을 이어붙이는 것을 뜻한다. 예를 들어, a="abc",
b="def"일 때, a*b="abcdef"이다. 이러한 이어 붙이는 것을 곱셈으로 생각한다면, 음이 아닌 정수의 제곱도 정의할 수
있다. a^0 = "" (빈 문자열) a^(n+1) = a*(a^n) 문자열 s가 주어졌을 때, 어떤 문자열 a에 대해서 s=a^n을
만족하는 가장 큰 n을 찾는 프로그램을 작성하시오.
@ Input: 입력은 10개 이하의 테스트 케이스로 이루어져 있다. 각각의 테스트 케이스는 s를 포함한 한 줄로 이루어져 있다. s의 길이는 적어도
1이며, 백만글자를 넘지 않는다. 마지막 테스트 케이스의 다음 줄은 마침표이다.
@ Output: 각각의 테스트 케이스에 대해, s=a^n을 만족하는 가장 큰 n을 찾은 뒤 출력한다.
@ Ref: https://zoosso.tistory.com/524
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


while True:
    s = input()
    if s == ".":
        break

    ans = 1
    pi = get_partial_table(s)

    l = len(pi) - pi[-1]
    if len(pi) % l == 0:
        print(len(pi) // l)
    else:
        print(1)
