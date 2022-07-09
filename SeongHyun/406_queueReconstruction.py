def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x:(x[0],-x[1]),reverse=True)
        result = [0 for _ in range(len(people))]
        while people:
            person = people.pop()
            checker = 0
            for j in range(len(result)):
                if result[j]==0 and person[1]==0:
                    result[j] = person
                    break
                elif result[j]==0:
                    checker += 1
                if checker == person[1]+1:
                    result[j] = person
                    break
        return result
