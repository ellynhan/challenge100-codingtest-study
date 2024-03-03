#include <iostream>
#include <vector>
#include <string>
#include <cstring>
//1051
using namespace std;
using ll = long long;

int n, m;
vector<string> s;
int dx[] = {0,1,1};
int dy[] = {1,0,1};

int search(int x, int y, char tar) {
	int maxval = 0;
	for(int i=0; x+i<n && y+i<m; i++) {
		bool check = true;
		for(int k=0; k<3; k++) {
			char tmp = s[x+i*dx[k]][y+i*dy[k]];
			if(tmp!=tar) {
				check = false;
				break;
			}
		}
		if(check && maxval<(i+1)*(i+1)) {
			maxval = (i+1)*(i+1);
		}
	}

	return maxval;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string tmp;
	int maxval = 0, result;
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		s.push_back(tmp);
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			result = search(i,j,s[i][j]);
			if(maxval < result) maxval = result;
		}
	}
	cout << maxval;
}