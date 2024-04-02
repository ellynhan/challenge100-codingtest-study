#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    if(n == 1) return answer;

    int sum{};
    int pos = 1;
    for(int i = pos; i <= (n%2==0 ? n/2 : n/2+1); i++){
        sum += i;
        if(sum == n) answer++;
        
        if(sum >= n){
            pos++;
            i = pos;
            i--;
            sum = 0;
        }
    }
    
    return answer;
}
