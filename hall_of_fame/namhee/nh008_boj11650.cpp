#include <iostream>
#include <algorithm>

using namespace std;

struct coordinate {
	int x;
	int y;
};
bool comp(coordinate a, coordinate b);
coordinate coord [100001];

int main() {
	// 1. INPUT DATA
	int N;
	cin >> N;
	
	for (int i=0; i<N; i++)
		cin >> coord[i].x >> coord[i].y;
	
	// 2. SORT
	sort(coord, coord+N, comp);
	
	// 3. OUTPUT DATA
	for (int i=0; i<N; i++)
		cout << coord[i].x << ' ' << coord[i].y << '\n';
}

bool comp(coordinate a, coordinate b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
