class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(itertools.combinations([num for num in range(1,n+1)],k))
