const int MAX = 100+2; //출발점, 도착점 포함
 
vector<int> graph[MAX];
bool visited[MAX];
 
//맨해튼 거리 : (x1-x2)+(y1-y2)
int distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
 
void DFS(int now){
    visited[now] = true;
    for (int i=0; i<graph[now].size(); i++){
        int next = graph[now][i];
        if (visited[next] == false)
            DFS(next);
    }
}
 
int main(){
    int t,n;
    scanf("%d",&t);
    for (int k=0; k<t; k++){
        for (int i=0; i<MAX; i++)
                graph[i].clear();    //vector의 clear()
        memset(visited, false, sizeof(visited));
 
        scanf("%d",&n);
        vector<pair<int, int>> loc;
 
        //출발점(0), 도착점(n+1) 포함
        for (int i=0; i<n+2; i++){
            int y, x;
            scanf("%d %d", &y,&x);
            loc.push_back(make_pair(y, x));
        }
 
        //맥주 20병으로 갈 수 있는 거리 내에 있으면 그래프에 추가
        for(int i=0; i<n+2; i++)
            for(int j=i+1; j<n+2; j++)
                if (distance(loc[i],loc[j]) <= 50*20){
                    //양방향 그래프
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
        DFS(0);
 
        //0이 출발점, n+1이 도착점이므로
        if (visited[n + 1])
            printf("happy\n");
        else
            printf("sad\n");
    }
}
