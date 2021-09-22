# 6:42
import sys

global answer


def solution(begin, target, words):
    global answer
    answer = sys.maxsize

    if target not in words:
        return 0

    def dfs(begin, target, words, ans):
        global answer

        if target == begin:
            if ans < answer:
                answer = ans

        sub_words = []

        for word in words:
            if word == "":
                continue

            count = 0

            for i, c in enumerate(word):
                if begin[i] != c:
                    count += 1
            print("Count 비교:", begin, word, count)

            if count == 1:
                sub_words.append(word)
                words[words.index(word)] = ""

                print(words, word, ans + 1)

        if target in sub_words:
            answer = ans + 1

        for sub_word in sub_words:
            dfs(sub_word, target, words, ans + 1)

    dfs(begin, target, words, 0)
    return answer