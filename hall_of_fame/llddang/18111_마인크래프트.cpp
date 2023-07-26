#include <iostream>
using namespace std;

int map[500][500];

int main(){
    int N, M, B; cin >> N >> M >> B;
    int s=INT32_MAX, e;
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        cin >> map[i][j];
        s = min(s, map[i][j]);
        e = max(e, map[i][j]);
    }

    int answer=INT32_MAX, answerH;
    int time, eraseBlock, addBlock;
    for(int h= s; h <= e; h++){
        eraseBlock = 0; addBlock = 0;

        for(int i=0; i<N; i++)
        for(int j=0; j<M; j++){
            if(map[i][j] > h){
                eraseBlock += map[i][j] - h;
            } else if(map[i][j] < h){
                addBlock += h - map[i][j];
            }
        }

        if(addBlock > eraseBlock + B) continue;

        time = eraseBlock * 2 + addBlock;

        if(answer > time){
            answer = time;
            answerH = h;
        } else if(answer == time && answerH < h) answerH = h;
    }

    cout << answer << " " << answerH;
}
