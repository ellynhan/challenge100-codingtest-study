#include <iostream>
using namespace std;

int trees[1000000];

int main(){
    int N, M; cin >> N >> M;
    int s=0, e=0, m;
    for(int i=0; i<N; i++){
        cin >> trees[i];
        e = max(e, trees[i]);
    }

    long long sum;
    int answer;
    while(s <= e){
        m = (s + e + 1) / 2;
        sum = 0;
        for(int i=0; i<N; i++){
            if(trees[i] - m <= 0) continue;
            sum += trees[i] - m;
        }
        if(sum > M){
            s = m + 1;
            answer = m;
        } else if(sum < M){
            e = m - 1;
        } else {
            answer = m;
            break;
        }
    }

    cout << answer;
}
