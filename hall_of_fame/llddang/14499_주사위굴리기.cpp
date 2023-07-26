#include <iostream>
#include <vector>
using namespace std;

int map[20][20];
vector<int> answer;

int main(){
    int N, M, ci, cj, K; cin >> N >> M >> ci >> cj >> K;
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) cin >> map[i][j];

    int dice[7] = {0, };
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, 1, -1, 0};

    int ni, nj;

    int dir; 
    int tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    for(int i=0; i<K; i++){
        cin >> dir;

        ni = ci + di[dir % 4];
        nj = cj + dj[dir % 4];
        if(0 > ni || ni >= N || 0 > nj || nj >= M) continue;

        if(dir == 1){
            tmp1 = dice[1];
            tmp3 = dice[3];
            tmp4 = dice[4];
            tmp6 = dice[6];
            dice[1] = tmp3;
            dice[3] = tmp6;
            dice[4] = tmp1;
            dice[6] = tmp4;
        } else if(dir == 2){
            tmp1 = dice[1];
            tmp3 = dice[3];
            tmp4 = dice[4];
            tmp6 = dice[6];
            dice[1] = tmp4;
            dice[3] = tmp1;
            dice[4] = tmp6;
            dice[6] = tmp3;
        } else if(dir == 3){
            tmp1 = dice[1];
            tmp2 = dice[2];
            tmp5 = dice[5];
            tmp6 = dice[6];
            dice[1] = tmp2;
            dice[2] = tmp6;
            dice[5] = tmp1;
            dice[6] = tmp5;
        } else if(dir == 4){
            tmp1 = dice[1];
            tmp2 = dice[2];
            tmp5 = dice[5];
            tmp6 = dice[6];
            dice[1] = tmp5;
            dice[2] = tmp1;
            dice[5] = tmp6;
            dice[6] = tmp2;
        }
        answer.push_back(dice[6]);
        ci = ni; cj = nj;
        if(map[ci][cj] == 0){
            map[ci][cj] = dice[1];
        } else {
            dice[1] = map[ci][cj];
            map[ci][cj] = 0;
        }
    }
    for(int i=0; i<answer.size(); i++) cout << answer[i] << "\n";
}
