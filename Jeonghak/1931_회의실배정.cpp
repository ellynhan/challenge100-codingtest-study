#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, cnt=0;
    vector<pair<int, int>> schedule;

    cin >> N;
    for(int i=0; i<N; i++){
        int start, end;
        cin >> start >> end;
        schedule.push_back({end, start});
    }
    sort(schedule.begin(), schedule.end());
    int curEnd = schedule[0].first; cnt++;
    for(int i=1; i<N; i++) {
        if(schedule[i].second >= curEnd) {
            cnt++;
            cout << schedule[i].first << ' ' << schedule[i].second << '\n';
            curEnd = schedule[i].first;
        }
    };
	cout << cnt;
}   
