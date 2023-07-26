import collections
import sys

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:  
        anagrams = collections.defaultdict(list)
        
        for w in strs:
            sorted_w = w
            sorted_w = sorted(sorted_w)
            anagrams[''.join(sorted_w)].append(w)

        #print(anagrams)
        #print(anagrams.values())

        return list(anagrams.values())

            

sol = Solution()
sol.groupAnagrams(strs = ["eat","tea","tan","ate","nat","bat"])