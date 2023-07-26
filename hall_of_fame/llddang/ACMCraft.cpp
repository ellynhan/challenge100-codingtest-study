#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void calcTime(int);
struct node{
    node(int n, int t, int tt=0, int p=0):
        name{n}, time{t}, totalT{tt}, parent{p} {}
    int name;
    int time;
    int totalT=0;
    int parent=0;
    vector<int> store;
};
vector<node> panda;

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i<N; i++){
        int nodeN, ruleN;
        cin >> nodeN >> ruleN;

        for(int j=0; j < nodeN; j++){
            int time; cin >> time;
            panda.push_back(node(j+1, time));
        }

        vector<int> start;
        for(int j=0; j < ruleN; j++){
            int tmp1, tmp2; cin >> tmp1 >> tmp2;
            panda[tmp1-1].store.push_back(tmp2);
            panda[tmp2-1].parent++;
        }
        int dest; cin >> dest;

        queue<int> Q;
        for(int j=0; j<nodeN; j++){
            if(panda[j].parent == 0){
                Q.push(j+1);
                panda[j].totalT = panda[j].time;
            }
        }

        while(!Q.empty()){
            int curr = Q.front();
            Q.pop();

            for(int j=0; j<panda[curr-1].store.size(); j++){
                int next = panda[curr-1].store[j];
                panda[next-1].totalT = max(panda[next-1].totalT, panda[curr-1].totalT + panda[next-1].time);
                panda[next-1].parent--;

                if(panda[next-1].parent == 0) Q.push(next);
            }

        }

        cout << panda[dest-1].totalT << "\n";
        panda.clear();
    }
}

