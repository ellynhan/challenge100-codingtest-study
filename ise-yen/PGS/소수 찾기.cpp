#include <vector>
#include <cmath>

using namespace std;

int era[1000001]{};

int eratos(int N){
    int cnt = 0;
    era[0] = -1;
    era[1] = -1;
    
    for(int i = 2; i <= N; i++){
        if(era[i] != 0) continue;
        bool isPrime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(era[j] != 1) continue;
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            era[i] = 1;
            cnt++;
        }
        else era[i] = -1;
    }
    return cnt;
}

int solution(int N) {
    int answer = 0;
    answer = eratos(N);
    return answer;
}
