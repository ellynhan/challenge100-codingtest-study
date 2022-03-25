from copy import deepcopy
import sys


def pseudo_palindrome(s: list):
    return s == s[::-1]


def palindrome(s: list):
    left = 0
    right = len(s)-1
    while left < right:
        # print(left, right)
        if s[left] == s[right]:
            left += 1
            right -= 1
            continue

        if s[left] != s[right]:
            if pseudo_palindrome(s[left + 1:right + 1]):
                return 1
            elif pseudo_palindrome(s[left:right]):
                return 1
            else:
                return 2
    return 0


T = int(sys.stdin.readline())
for _ in range(T):
    print(palindrome(list(sys.stdin.readline().rstrip())))
