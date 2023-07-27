class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)

        for s in strs:
            count = [0] * 26
            
            for char in s:
                count[ord(char) - ord('a')] += 1

            ans[tuple(count)].append(s)

        return ans.values()
