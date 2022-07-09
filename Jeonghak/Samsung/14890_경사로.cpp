#include<iostream>
#define MAX 101
using namespace std;
int N, L, answer = 0;
int map[MAX][MAX];
void Input()
{
    cin >> N >> L;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
}
void Transpose()
{
    int temp = 0;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            temp = map[i][j];
            map[i][j] = map[j][i];
            map[j][i] = temp;
        }
    }
}
void Validate()
{
    for(int i=0; i < N; i++){
        int curr_value = map[i][0];
        int curr_cnt = 1;
        for(int j=1; j < N; j++)
        {
            // 경사가 같으면 count만 증가
            if(curr_value == map[i][j]){
                curr_cnt++;
            }
            // 높이의 차가 1일 때
            else if(map[i][j] - curr_value == 1){
                // 이때까지 지나왔던 거리가 L과 같거나 크면 경사로 설치 가능
                if(curr_cnt >= L){
                    curr_value = map[i][j];
                    curr_cnt = 1;
                } else {
                    break;  // 경사로를 설치하지 못하면 멈춤
                }
            }
            // 높이의 차가 -1일 떄
            else if(curr_value - map[i][j] == 1){
                bool isAble = true;
                curr_value = map[i][j];
                // L 만큼 이동해보며 설치 가능한지 검사
                for(int k=j; k < j + L; k++){
                    if(map[i][k] != curr_value){
                        isAble = false;
                        break;
                    }
                }
                if(isAble){
                    j += L - 1;
                    curr_cnt = 0;
                } else break;
            }
            else break;
            if(j == N-1) {
                answer++;
            }
        }
    }
}
int main()
{
    Input();
    Validate();
    Transpose();
    Validate();
    cout << answer;   
}