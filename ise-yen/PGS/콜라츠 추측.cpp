#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while(n != 1){
        answer++;
        if(n % 2 == 0) n /= 2;
        else {
            n *= 3;
            n++;
        }
        
        if(answer == 500){
            answer = -1;
            break;
        }
    }
    return answer;
}
