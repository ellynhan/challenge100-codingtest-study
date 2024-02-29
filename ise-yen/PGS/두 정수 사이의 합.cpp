#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if(a == b) return a;
    
    int s{}, e{};
    if(a < b){
        s = a;
        e = b;
    }
    else{
        s = b;
        e = a;
    }
    
    for(s; s <= e; s++){
        answer += s;
    }
    return answer;
}
