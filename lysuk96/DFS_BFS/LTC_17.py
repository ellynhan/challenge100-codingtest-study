'''
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
'''
from typing import List

def letterCombinations(digits: str) -> List[str]:
    dic={
        '2' : ['a','b','c'],
        '3' : ['d','e','f'],
        '4' : ['g','h','i'],
        '5' : ['j','k','l'],
        '6': ['m','n','o'],
        '7': ['p','q','r','s'],
        '8': ['t','u','v'],
        '9': ['w','x','y','z']
    }
    ans = []

    def dfs(index, path):
        print(path)
        if len(path) == len(digits):
            print(index)
            ans.append(path)
            return
        
        for i in range(index, len(digits)):
            for j in dic[digits[i]]:
                dfs(i+1,path+j)

    if digits =="":
        return []
        
    dfs(0,"")
    return ans

        
    
print(letterCombinations("23"))