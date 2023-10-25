N, M = map(int, input().split())
books = list(map(int, input().split()))

positive_books = sorted([book for book in books if book > 0], reverse=True)
negative_books = sorted([book for book in books if book < 0])

print(positive_books)
print(negative_books)
# M씩 끊어서 처리
steps = 0
for i in range(0, len(positive_books), M):
    steps += positive_books[i] * 2

for i in range(0, len(negative_books), M):
    steps += abs(negative_books[i]) * 2

# 가장 멀리 있는 책(가장 큰 이동 거리를 요하는 책)의 이동 거리는 한 번만 계산
max_distance = 0
if positive_books:
    max_distance = max(max_distance, positive_books[0])
if negative_books:
    max_distance = max(max_distance, abs(negative_books[0]))

steps -= max_distance

print(steps)
