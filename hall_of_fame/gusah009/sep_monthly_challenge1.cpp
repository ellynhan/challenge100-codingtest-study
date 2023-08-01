#include <string>
#include <vector>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;


int solution(vector<int> numbers) {
    int answer = 0;
    FOR(i, 10) {
        answer += i;
    }
    FOR(i, numbers.size()) {
        answer -= numbers[i];
    }
    return answer;
}