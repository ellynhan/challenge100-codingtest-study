class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        result = collections.deque()
        num_letter = {
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z']
        }

        for digit in digits:
            if not result:
                for char in num_letter[digit]:
                    result.append(char)
                continue
            len_result = len(result)
            for _ in range(len_result):
                string = result.popleft()
                for char in num_letter[digit]:
                    result.append(string+char)

        return result
