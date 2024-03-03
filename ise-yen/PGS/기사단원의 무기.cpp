#include <string>
#include <vector>
#include <cmath>

using namespace std;

int divisor(int n){
    int cnt{};
    for(int i = 1; i <= sqrt(n); i++){
        if(i == sqrt(n)){
            if(i * i == n){
                cnt++;
            }
            continue;
        }
        if(n % i == 0) cnt += 2;
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int n = 1; n <= number; n++){
        int div = divisor(n);
        if(div <= limit) answer += div;
        else answer += power;
    }
    return answer;
}
