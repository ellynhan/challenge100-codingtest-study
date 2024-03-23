#include <string>
#include <vector>

using namespace std;

const int N = 1234567;
const int MAX = 100001;
vector<int> memo(MAX, -1);

int recur(int n){
    if(n == 0) return memo[0] = 0;
    else if(n == 1) return memo[1] = 1;
    if(memo[n] != -1) return memo[n];
    else return memo[n] = recur(n-1)%N + recur(n-2)%N;
}

int solution(int n) {
    memo[0] = 0;
    memo[1] = 1;
    recur(n);
    int answer = memo[n] % N;
    return answer;
}
