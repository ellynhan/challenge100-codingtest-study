a = sorted(set(input() for _ in range(int(input()))))
print('\n'.join(sorted(a, key=len)))
