#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct NODE{int s, e, c;};

int main(){
    vector<string> answers;
    int T; cin >> T;
    while(T--){
        int N, M, W; cin >> N >> M >> W;

        int s, e, c;
        vector<NODE> edge;
        vector<bool> check(N+1, true);
        while(M--){
            cin >> s >> e >> c;
            edge.push_back({s, e, c});
            edge.push_back({e, s, c});
        }
        while(W--){
            cin >> s >> e >> c;
            edge.push_back({s, e, -c});
            check[s] = false;
            check[e] = false;
        }

        int E = edge.size();
        int i, j, k;
        for(k=1; k<=N; k++){
            if(check[k]) continue;
            vector<int> dist(N+1, INF);
            dist[k] = 0;

            for(i=0; i<N; i++)
            for(j=0; j<E; j++){
                s = edge[j].s;
                e = edge[j].e;
                c = edge[j].c;

                if(dist[s] == INF) continue;
                if(dist[s] + c < dist[e])
                    dist[e] = dist[s] + c;
            }

            for(i=0; i<E; i++){
                s = edge[i].s;
                e = edge[i].e;
                c = edge[i].c;

                if(dist[s] == INF) continue;
                if(dist[s] + c < dist[e]) break;
            }
            if(i != E) break;
        }
        if(k == N+1) answers.push_back("NO");
        else answers.push_back("YES");
    }

    for(string a : answers) cout << a << "\n";
}
