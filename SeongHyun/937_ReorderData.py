class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        let = []
        dig = []
        result = []
        for log in logs:
            tmp = (' '.join(log.split()[1:]), log.split()[0])
            if tmp[0].replace(" ","").isalpha():
                heapq.heappush(let, tmp)
            else:
                dig.append(log)
        while let:
            tmp = heapq.heappop(let)
            result.append(tmp[1]+" "+tmp[0])
        return result + dig
-----------------------------------------------------------------------------
another solution
-----------------------------------------------------------------------------
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def is_log(log):
            return ' '.join(log.split()[1:])
        return sorted(
          [log for log in logs if is_log(log).replace(" ","").isalpha()],
          key=lambda x: (is_log(x), x.split()[0])
        ) + [log for log in logs if is_log(log).replace(" ","").isnumeric()]
