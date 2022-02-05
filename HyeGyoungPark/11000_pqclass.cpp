#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int num,i,s,t;

	vector <pair<int, int>> time;
	priority_queue<int, vector<int>, greater<int> > pq;

	cin >> num;

	for (i = 0; i < num; i++) {
        cin >> s >> t;
        time.push_back(pair<int,int>(s,t));
	}

	sort(time.begin(), time.end());

	pq.push(time[0].second);

	for (i = 1; i < num; ++i) {
		if (pq.top() <= time[i].first) {
			pq.pop();
			pq.push(time[i].second);
		}
		else {
			pq.push(time[i].second);
		}
	}

	cout << pq.size() << endl;

	return 0;
}
