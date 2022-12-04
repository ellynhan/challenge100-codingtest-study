#include <iostream>
#include <vector>
#include <map>
#define MAX 25
using namespace std;
map<int, vector<int>> studentMap;
int seats[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct Student{
    int num;
    vector<int> favoriteFriends;
};
struct seatInfo{
    int empty = 0;
    int favorite = 0;
};
Student students[MAX*MAX];
int N;

void Input()
{
    cin >> N;
    for(int i=0; i<N*N; i++){
        cin >> students[i].num;
        for(int j=0; j<4; j++){
            int x;
            cin >> x;
            students[i].favoriteFriends.push_back(x);
        }
        studentMap.insert({students[i].num, students[i].favoriteFriends});
    }
}

void assignSeat(int idx)
{
    seatInfo best, curr;
    int nx=0, ny=0, best_x=0, best_y=0; 
    best.empty = -1;
    best.favorite = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(seats[i][j] != 0)
                continue;
            curr.empty = 0;
            curr.favorite = 0;
            // 상하좌우 친한친구, 빈칸 조사
            for(int k=0; k<4; k++){
                nx = j + dx[k];
                ny = i + dy[k];
                if(nx >= 0 && nx < N && ny >=0 && ny < N){
                    // 빈칸 
                    if(seats[ny][nx] == 0)
                        curr.empty++;
                    // 좋아하는 친구가 있는지
                    for(int m=0; m<4; m++){
                        if(seats[ny][nx] == students[idx].favoriteFriends[m])
                            curr.favorite++;
                    }
                }
            }
            if(best.favorite < curr.favorite){
                best.favorite = curr.favorite;
                best.empty = curr.empty;
                best_x = j;
                best_y = i;
            } else if(best.favorite == curr.favorite) {
                if(best.empty < curr.empty){
                    best.favorite = curr.favorite;
                    best.empty = curr.empty;
                    best_x = j;
                    best_y = i;
                }
            }
        }
    }
    seats[best_y][best_x] = students[idx].num;
}

int computeScore(){
    int score = 0, favorite = 0, nx=0, ny=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            favorite = 0;
            // 상하좌우 친한친구, 빈칸 조사
            for(int k=0; k<4; k++){
                nx = j + dx[k];
                ny = i + dy[k];
                if(nx >= 0 && nx < N && ny >=0 && ny < N){
                    // 좋아하는 친구가 있는지
                    for(int m=0; m<4; m++){
                        if(seats[ny][nx] == studentMap[seats[i][j]][m])
                            favorite++;
                    }
                }
            }
            if(favorite==1) score+=1;
            else if(favorite==2) score += 10;
            else if(favorite==3) score += 100;
            else if(favorite==4) score += 1000;
            else score = score;
        }
    }
    return score;
}
int main(){
    int score=0;
    Input();
    for(int i=0; i<N*N; i++)
    {
        assignSeat(i);
    }
    score = computeScore();
    cout << score;
}