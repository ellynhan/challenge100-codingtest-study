class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = collections.Counter(nums)
        heap = []
        result = []
        
        for num, freq in counter.items():
            heapq.heappush(heap, (-freq, num))
        
        for _ in range(k):
            result.append(heapq.heappop(heap)[1])
        
        return result
      
