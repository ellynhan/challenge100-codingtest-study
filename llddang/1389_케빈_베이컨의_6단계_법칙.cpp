#include <iostream>
using namespace std;

int friends[101][101] = {0};

int main(){
    int N, M; cin >> N >> M;

    int a, b;
    while(M--){
        cin >> a >> b;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    bool check = true;
    int k, tmpValue;
    for(int cnt = 1; check; cnt++){
        check = false;
        for(int i=1; i<N+1; i++){
        for(int j=i+1; j<N+1; j++){
            if(friends[i][j] != 0) continue;
            tmpValue = INT32_MAX;
            for(k=1; k<N+1; k++){
                if(friends[i][k] == 0 || friends[k][j] == 0) continue;
                if(friends[i][k] > cnt || friends[k][j] > cnt) continue;

                tmpValue = min(tmpValue, friends[i][k] + friends[k][j]);
            }
            if(tmpValue == INT32_MAX) check = true;
            else friends[i][j] = tmpValue, friends[j][i] = tmpValue;
        }
        }
    }
    
    int answerIdx=0, answerValue = INT32_MAX, sum;
    for(int i=1; i<N+1; i++){
        sum = 0;
        for(int j=1; j<N+1; j++){
            sum += friends[i][j];
        }

        if(sum < answerValue){
            answerValue = sum;
            answerIdx = i;
        }
    } 

    cout << answerIdx;
}
