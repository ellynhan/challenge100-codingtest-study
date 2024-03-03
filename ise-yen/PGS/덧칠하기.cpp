#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    int pos = section[0];
    answer++;
    
    bool flag = false;
    for(int i = 1; i < section.size(); i++){
        // 이전에 칠한 범위를 벗어나면 : 새로 칠해야함
        if(section[i] > pos + m - 1){
            // 새로 칠할 범위에서 페인트칠을 해도 벽 범위 이내라면
            if(section[i] + m - 1 <= n){
                pos = section[i]; // 갱신
                answer++; // 횟수 추가
            }
            else{ // 벽 범위를 벗어나면
                // 좀더 위에서 칠하기 : tp=임시위치
                for(int tp = section[i]-1; tp > pos; tp--){
                    if(tp + m - 1 == n){
                        if(pos != tp){
                            answer++;
                        }
                        flag = true;
                        break;
                    }
                }
                
                if(flag) break;
            }
        }
    }
    return answer;
}
