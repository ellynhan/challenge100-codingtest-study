//0211 ~ 0236
//0312 ~ 0327
#include <iostream>
#include <stack>

using namespace std;
int R, C;
stack<int> st;

void location(int startR, int endR, int startC, int endC) {
	int midR = (endR-startR) / 2;
	int midC = (endC-startC) / 2;
	int lo = 0;
	if (R < startR+midR) {
		endR = startR + midR;
		if (C < startC+midC) {
			lo = 0;
			endC = startC + midC;
		}
		else {
			lo = 1;
			startC = startC + midC;
		}
	}
	else {
		startR = startR + midR;
		if (C < startC+midC) {
			lo = 2;
			endC = startC + midC;
		}
		else {
			lo = 3;
			startC = startC + midC;
		}
	}
	st.push(lo);
	if (midR == 1) {
		return ;
	}
	else {
		location(startR, endR, startC, endC);
	}
}



int  main() {
	int N, ans = 0, carry = 1;
	cin >> N >> R >> C;
	location(0, 1 << N, 0, 1 << N);
	while (!st.empty()) {
		ans += st.top() * carry;
		carry *= 4;
		st.pop();
	}
	cout << ans;
}

//처음 가로 세로에서 나누기 2를 해서 1~4사분면중 어디인지 확인한다
//해당하는 사분면중에서 가로 세로 나누기를 2를 해서 1~4분면중 어디인지 확인한다. 
//...
//가로세로길이가 각각 2가되었을떄도 1~4분면중 어디인지 확인한다.
//4분면인 경우 + 3*(1)
//확장후 3사분면인경우 + 2*(4)
//확장후 4사분면인경우 + 3*(4*4)
//...
