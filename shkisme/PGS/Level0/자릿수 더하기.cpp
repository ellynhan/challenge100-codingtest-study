#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    string str = to_string(n);

    for (char c : str){
        answer += c - '0';
    }

    return answer;
}
