#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= '0' && s[i] <= '9')) {
            answer *= 10;
            answer += (s[i] - '0');
            continue;
        }
        else {
            if (s[i] == 'z') {                  // 0
                answer *= 10;
                i += 3;
                continue;
            }
            if (s[i] == 'o') {                  // 1
                answer *= 10;
                answer += 1;
                i += 2;
                continue;
            }
            if (s[i] == 't') {
                if (s[i+1] == 'w') {            // 2
                    answer *= 10;
                    answer += 2;
                    i += 2;
                    continue;
                }
                if (s[i+1] == 'h') {            // 3
                    answer *= 10;
                    answer += 3;
                    i += 4;
                    continue;
                }
            }
            if (s[i] == 'f') {
                if (s[i+1] == 'o') {            // 4
                    answer *= 10;
                    answer += 4;                    
                    i += 3;
                    continue;
                }
                if (s[i+1] == 'i') {            // 5
                    answer *= 10;
                    answer += 5;
                    i += 3;
                    continue;
                }
            }
            
            if (s[i] == 's') {
                if (s[i+1] == 'i') {            // 6
                    answer *= 10;
                    answer += 6;
                    i += 2;
                    continue;
                }
                if (s[i+1] == 'e') {            // 7
                    answer *= 10;
                    answer += 7;
                    i += 4;
                    continue;
                }
            }
            
            if (s[i] == 'e') {                  // 8
                answer *= 10;
                answer += 8;
                i += 4;
                continue;
            }
            
            if (s[i] == 'n') {                  // 9
                answer *= 10;
                answer += 9;
                i += 3;
                continue;
            }
        }
    }
    return answer;
}
