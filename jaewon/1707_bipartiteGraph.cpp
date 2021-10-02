#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
bool bfs(int start, map<int,vector<int>>& rel, map<int, int>& colored){
    queue<int> q;
    q.push(start);
    colored[start]=1;
    bool possi = true;
    while(!q.empty()&&possi){
        int curr = q.front();
        q.pop();
        vector<int> tmp = rel[curr];
        for(int i=0; i<tmp.size()&&possi; i++){
            if(colored[tmp[i]]==0){
                q.push(tmp[i]);
                if(colored[curr]==1){
                    colored[tmp[i]]=2;
                }else{
                    colored[tmp[i]]=1;
                }
            }else{
                if(colored[tmp[i]]==colored[curr]){
                    possi = false;
                }
            }
        }
    }
    return possi;
}

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int v, e;
        cin >> v >> e;
        map<int, vector<int> > rel;
        map<int, int> colored;
        int a,b;
        for(int i=0; i<e; i++){
            cin >> a >> b;
            rel[a].push_back(b);
            rel[b].push_back(a);
            colored[a]=0;
            colored[b]=0;
        }
        map<int,int>::iterator it;
        bool result = true;
        for(it=colored.begin(); it!=colored.end()&&result; it++){
            if(it->second==0){
                result = bfs(it->first,rel,colored);
            }
        }
        if(result){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
