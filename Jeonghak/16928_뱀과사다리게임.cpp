#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int map[101];
int ladderOrSnake[101];
queue<int> q;

void BFS(){
    memset(map, -1, sizeof(map));
    q.push(1);
    map[1] = 0;
    while(!q.empty())
    {
        int currLoc = q.front();
        q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int nextLoc = currLoc + i;
			if (nextLoc > 100) continue;
			if (ladderOrSnake[nextLoc] != 0) {
				nextLoc = ladderOrSnake[nextLoc];
			}
			if (map[nextLoc] == -1) {
				map[nextLoc] = map[currLoc] + 1;
				q.push(nextLoc);
			}
		}
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for(int i=0; i < N+M; i++){
        int start, end;
        cin >> start >> end;
        ladderOrSnake[start] = end;
    }
    BFS();
    cout << map[100];
}