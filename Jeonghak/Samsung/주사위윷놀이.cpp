#include <iostream>

using namespace std;
int graph[33];
int horse[4];
bool check[33];
int dice[10];
int switchBlueDir[33];
int switchDir[33];
int answer;

void initGraph() {
    for(int i=1; i < 21; i++) {
        graph[i] = i*2;
    }
    graph[22] = 13; graph[23] = 16; graph[24] = 19;
    graph[25] = 22; graph[26] = 24;
    graph[27] = 28; graph[28] = 27; graph[29] = 26;
    graph[30] = 25; graph[31] = 30; graph[32] = 35;
}

void initSwitchDir() {
    // 파란색 칸 방향 전환
    switchBlueDir[5] = 22;
    switchBlueDir[10] = 25;
    switchBlueDir[15] = 27;
    
    // 도착 칸 
    switchDir[21] = 21;

    // 19, 24, 26, 35 다음 칸 설정
    switchDir[32] = 20;
    switchDir[24] = switchDir[26] = switchDir[29] = 30;
}

void dfs(int depth, int sum) {

    if(depth == 10) {
        answer = max(answer, sum);
        return;
    }

    for(int i=0; i<4; i++) {
        int prevLoc = horse[i];
        int currLoc = prevLoc;
        int move = dice[depth];

        // 파란색 칸 다음 칸 설정
        if(switchBlueDir[currLoc]) {
            currLoc = switchBlueDir[currLoc];
            move--;
        }

        for(int i=0; i<move; i++) {
            // 19, 24, 26, 35 다음 칸 설정
            if(switchDir[currLoc]) 
                currLoc = switchDir[currLoc];
            else currLoc++;
            // 도착 칸이면 정지
            if(currLoc == 21) break;
        }
        
        if (currLoc != 21 && check[currLoc] == true) continue;

        check[prevLoc] = false;
        check[currLoc] = true;
        horse[i] = currLoc;

        dfs(depth + 1, sum + graph[currLoc]);

        horse[i] = prevLoc;
        check[prevLoc] = true;
        check[currLoc] = false;
    }
}

int main() {
    initGraph();
    initSwitchDir();

    for(int i=0; i<10; i++)
        cin >> dice[i];

    dfs(0, 0); 
    cout << answer;
}