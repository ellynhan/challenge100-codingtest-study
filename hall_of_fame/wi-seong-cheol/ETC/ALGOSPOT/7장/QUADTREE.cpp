//
//  QUADTREE.cpp
//  main
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 4
 w
 xbwwb
 xbwxwbbwb
 xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
 [Output]
 w
 xwbbw
 xxbwwbbbw
 xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: 하
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/QUADTREE

#include <iostream>

using namespace std;
int t;
string s;

string reverse(string::iterator& it) {
    char head = *it;
    it++;
    if(head == 'b' || head == 'w') return string(1, head);
    
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> s;
        string::iterator it = s.begin();
        cout << reverse(it) << '\n';
    }

	return 0;
}
