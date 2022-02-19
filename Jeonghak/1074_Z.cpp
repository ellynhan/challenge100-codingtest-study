#include <iostream>

using namespace std;
int N, R, C, cnt=0;

void solve(int curX, int curY, int len){
    if(curX == R && curY == C) {
        cout << cnt; 
        return;
    }
    if(R < curX+len && curX <= R && C < curY+len && curY <= C){
        solve(curX, curY, len/2);               // 1사분면 탐색
        solve(curX, curY+len/2, len/2);         // 2사분면 탐색
        solve(curX+len/2, curY, len/2);         // 3사분면 탐색
        solve(curX+len/2, curY+len/2, len/2);   // 4사분면 탐색
    }
    else cnt += len*len;
}
int main(void)
{
    cin >> N >> R >> C;
    solve(0, 0, (1 << N));
}
