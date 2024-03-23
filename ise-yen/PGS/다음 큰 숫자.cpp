#include <string>
#include <vector>

using namespace std;

int cntOne(int n){
    int cnt{};
    while(n > 0){
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cnt = cntOne(n);
    while(true){
        n++;
        if(cnt == cntOne(n)){
            answer = n;
            break;
        }
    }
    return answer;
}
