#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int,int>> xy;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main(void){
    int n,x,y;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        xy.push_back(pair<int,int>(x,y));
    }

    sort(xy.begin(), xy.end(),cmp);

    for(int i=0; i<n; i++){
        cout << xy[i].first << " " << xy[i].second << "\n";
    }

    return 0;
}
