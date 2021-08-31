#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <set>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, peopleCount;
	vector<int> peoples;
	list<set<int>> groups;
	vector<list<set<int>>::iterator> check;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		cin >> peopleCount;

		peoples.clear();
		groups.clear();
		check.clear();

		check = vector<list<set<int>>::iterator>(peopleCount + 1);
		peoples = vector<int>(peopleCount + 1, -1);
		for (int i = 1; i < peopleCount + 1; i++) {
			int di;
			cin >> di;
			peoples[i] = i + di;
		}

		for (int i = peopleCount; i > 0; i--) {
			if (peoples[i] <= peopleCount) {
				check[peoples[i]]->insert(i);
				check[i] = check[peoples[i]];

			}
			else {
				groups.push_back(set<int>());
				groups.back().insert(i);
				check[i] = --groups.end();
			}
		}

		Answer = groups.size();

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}