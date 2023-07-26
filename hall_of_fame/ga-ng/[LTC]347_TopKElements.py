class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        import heapq as hq
        from collections import Counter

        count = Counter(nums)

        return hq.nlargest(k, count.keys(), key=count.get)
