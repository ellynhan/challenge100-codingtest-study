# [BOJ] 거짓말 / 골드4
# https://www.acmicpc.net/problem/1043

class Person:  # 사람 class, 참석 파티와 진실을 알고 있는지 여부를 저장
    def __init__(self, number):
        self.number = number
        self.partyAttend = []
        self.truth = False

    def attendParty(self, party):
        self.partyAttend.append(party)

    def getPartyAttend(self):
        return self.partyAttend

    def knowTruth(self):
        self.truth = True

    def getTruth(self):
        return self.truth

    def searchTrueParty(self):
        global lieParty
        for i in self.partyAttend:
            trueParty = i
            if not trueParty.getTruth():  # 진실이 안 퍼진 파티가 있다면
                trueParty.knowTruth()  # 진실이 퍼졌음을 표기함
                lieParty -= 1
                trueParty.searchTruePerson()  # 진실이 퍼진 파티는 진실을 모르는 다른 참석자를 탐색함


class Party:  # 파티 class, 참석자와 진실이 퍼져 있는지 여부를 저장
    def __init__(self, attendee, attendeeList):
        self.attendee = attendee
        self.attendeeList = attendeeList
        self.truth = False

    def getPeopleList(self):
        return self.attendeeList

    def knowTruth(self):
        self.truth = True

    def getTruth(self):
        return self.truth

    def searchTruePerson(self):
        for i in self.attendeeList:
            truePerson = peopleList[i-1]
            if not truePerson.getTruth():  # 진실을 모르는 참석자가 있다면
                truePerson.knowTruth()  # 진실을 알려줌
                truePerson.searchTrueParty()  # 진실을 안 참석자는 진실을 모르는 다른 파티를 탐색함


if __name__ == "__main__":
    firstLine = list(map(int, input().split(' ')))
    secondLine = list(map(int, input().split(' ')))

    peopleN = firstLine[0]
    partyM = firstLine[1]
    peopleList = []

    for i in range(peopleN):
        peopleList.append(Person(i+1))

    truePeople = secondLine[0]
    truePeopleList = secondLine[1:]

    lieParty = partyM
    partyList = []

    for i in range(partyM):
        partyLine = list(map(int, input().split(' ')))

        party = Party(partyLine[0], partyLine[1:])
        partyList.append(party)

        for j in party.getPeopleList():
            attendee = peopleList[j-1]
            attendee.attendParty(party)  # 참석자 class에 참석파티 목록 저장

    for i in truePeopleList:  # 진실을 아는 참석자들
        truePerson = peopleList[i-1]
        if not truePerson.getTruth():  # 진실을 아직 안퍼뜨린 참석자 라면
            truePerson.knowTruth()  # 표기를 해주고
            truePerson.searchTrueParty()  # 아직 진실을 모르는 파티를 탐색함

    print(lieParty)
