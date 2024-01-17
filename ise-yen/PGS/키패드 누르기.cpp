#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int map[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int posLr = 3, posLc = 0; // 왼손 엄지손가락 위치
    int posRr = 3, posRc = 2; // 오른손 엄지손가락 위치

    for(int i = 0; i < numbers.size(); i++){
        int n = numbers[i];
        if(n == 1 || n == 4 || n == 7) {
            answer.push_back('L');

            // 왼손 엄지손가락 위치 갱신
            for(int k = 0; k < 4; k++){
                if(n == map[k][0]){
                    posLr = k;
                    break;
                }
            }
            posLc = 0;
        }
        else if(n == 3 || n == 6 || n == 9) {
            answer.push_back('R');

            // 오른손 엄지손가락 위치 갱신
            for(int k = 0; k < 4; k++){
                if(n == map[k][2]){
                    posRr = k;
                    break;
                }
            }
            posRc = 2;
        }
        else{
            int tr{}, tc = 1; // 타겟 위치
            for(int k = 0; k < 4; k++){
                if(n == map[k][tc]){
                    tr = k;
                    break;
                }
            }

            // 현재 왼손 엄지손가락의 위치와의 거리
            int dL = abs(tr - posLr) + abs(tc - posLc);
            
            // 현재 오른손 엄지손가락의 위치와의 거리
            int dR = abs(tr - posRr) + abs(tc - posRc);
            
            if(dL < dR) {
                answer.push_back('L');
                posLr = tr;
                posLc = tc;
            }
            else if(dL > dR){
                answer.push_back('R');
                posRr = tr;
                posRc = tc;
            }
            else{
                if(hand == "left"){
                    answer.push_back('L');
                    posLr = tr;
                    posLc = tc;
                }
                else if(hand == "right"){
                    answer.push_back('R');
                    posRr = tr;
                    posRc = tc;
                }
            }
        }
    }
    return answer;
}
