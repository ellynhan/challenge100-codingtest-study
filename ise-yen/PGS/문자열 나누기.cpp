#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isSplit = true;
    char c{};
    int x{}, nx{};
    for(int i = 0; i < s.length(); i++){
        if(isSplit) {
            c = s[i];
            isSplit = false;
        }

        if(s[i] == c) x++;
        else nx++;
        
        if(x == nx){
            // 나누기
            isSplit = true;
            // 정답 갱신
            answer++;

            // 초기화
            x = 0;
            nx = 0;
        }
    }

    if(!isSplit) answer++;
    return answer;
}
