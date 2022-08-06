#include<iostream>
#define MAX 21
#define MAXDIFF 1000000000
using namespace std;
int N;
int min_diffrence = MAXDIFF;
int stat[MAX][MAX];
bool isStartTeam[MAX];

void Input()
{
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> stat[i][j];
        }
    }
}

void DFS(int depth, int position){
    if(depth == N/2){
        int start = 0;
        int link = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(isStartTeam[i] && isStartTeam[j]) start += stat[i][j];
                if(!isStartTeam[i] && !isStartTeam[j]) link += stat[i][j];
            }
        }
        int curr_diffrence = abs(start - link);
        min_diffrence = min(min_diffrence, curr_diffrence);
        
        return;
    }

    for(int i=position; i<N; i++){
        isStartTeam[i] = true;
        DFS(depth+1, i+1);
        isStartTeam[i] = false;
    }
}
int main(){
    Input();
    DFS(0, 0);
    cout << min_diffrence;
}