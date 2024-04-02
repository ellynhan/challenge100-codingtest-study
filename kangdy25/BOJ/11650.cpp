#include <bits/stdc++.h>
using namespace std;

struct Coord {
    int x;
    int y;
};

bool compare(Coord a, Coord b) {
	if (a.x == b.x) {			// x좌표가 같으면
		return a.y < b.y;		// b의 y좌표가 더 크도록 정렬 
	}
	else {						// x좌표가 다르면
		return a.x < b.x;		// b의 x좌표가 더 크도록 정렬 (=x좌표가 증가하는 순으로)
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    Coord result[100001];
    
    for (int i = 0; i < N; i++) {
        cin >> result[i].x >> result[i].y;
    }
    sort(result, result+N, compare);
    
    for (int i = 0; i < N; i++) {
        cout << result[i].x << " " << result[i].y << "\n";
    }
    
}