#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <set>
#include <utility>


using namespace std;

int main(void) {
	int peopleSize, partySize;
	int knowTruePeopleSize;
	cin >> peopleSize >> partySize >> knowTruePeopleSize;

	vector<bool> knowTruePeoples(peopleSize + 1, false);
	list<unordered_set<int>> graph;
	vector<unordered_set<int>> party;
	party.reserve(partySize);

	for (int i = 0; i < knowTruePeopleSize; i++) {
		int p;
		cin >> p;
		knowTruePeoples[p] = true;
	}

	for (int i = 0; i < partySize; i++) {
		bool know = false;
		int newPartySize;
		cin >> newPartySize;
		unordered_set<int> newParty;
		newParty.reserve(newPartySize);

		for (int j = 0; j < newPartySize; j++) {
			int p;
			cin >> p;
			newParty.insert(p);
			if (!know && knowTruePeoples[p])
				know = true;
		}

		graph.push_back(newParty);
		party.push_back(newParty);
	}

	for (int i = 1; i < peopleSize + 1; i++) {
		list<unordered_set<int>>::iterator placeToMerge = graph.end();
		for (list<unordered_set<int>>::iterator graphIter = graph.begin(); graphIter != graph.end(); graphIter++)
			if (graphIter->count(i)){
				if (placeToMerge != graph.end()) {
					placeToMerge->insert(graphIter->begin(),graphIter->end());
					graphIter = graph.erase(graphIter);
					graphIter--;
				}
				else
					placeToMerge = graphIter;
			}
	}


	for (const auto& graphIter : graph) {
		for (int iter : graphIter) {
			if (knowTruePeoples[iter]) {
				for (int iter : graphIter)
					knowTruePeoples[iter] = true;
				break;
			}
		}
	}

	int answer = 0;

	for (const auto& partyIter : party) {
		bool safe = true;
		for (int iter : partyIter)
			if (knowTruePeoples[iter]) {
				safe = false;
				break;
			}
				
		if (safe)
			answer++;
		
	}
	cout << answer << '\n';

	return 0;
}