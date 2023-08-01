#include <iostream>
#include <vector>
#include <queue>
#define boost ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main(){
    boost;
    int N; cin >> N;
    int visited[26] = {0};
    int indegree[26] = {0};
    vector<int> adj[26];
    int conn[26][26] = {0};
    int visitCnt = 0;
    bool impossible = false;
    bool moreThanOne = false;
    string answer = "";
    vector<string> dict;

    string word;
    for(int i=0; i<N; i++){
        cin >> word;
        dict.push_back(word);
        for(int j=0; j<word.length(); j++){
            int wordIdx = word[j] - 'a';
            if(visited[wordIdx] == 0){
                visited[wordIdx] = 1;
                visitCnt++;
            }
        }
    }

    for(int i=0; i<N-1; i++){
        for(int len = 0; len<dict[i].length(); len ++){
            if(len < dict[i+1].length()){
                if(dict[i][len] != dict[i+1][len]){
                    conn[dict[i][len]-'a'][dict[i+1][len]-'a'] = 1;
                    adj[dict[i][len]-'a'].push_back(dict[i+1][len]-'a');
                    indegree[dict[i+1][len]-'a'] ++;
                    break;
                }
            }else{
                impossible = true;
                break;
            }
        }
    }

    queue<int> q;
    for(int i=0; i<26; i++){
        if(visited[i]==1 && indegree[i]==0){
            q.push(i);
        }
    }

    //위상정렬
    while(!q.empty()){
        if(q.size() > 1){
            moreThanOne = true;
        }
        int wordIdx = q.front(); q.pop();
        answer += 'a'+wordIdx;
        visitCnt--;

        for(int j=0; j<adj[wordIdx].size(); j++){ //이렇게 하면 맞음
            if(--indegree[adj[wordIdx][j]]==0){
                q.push(adj[wordIdx][j]);
            }
        }
        // for(int j=0; j<26; j++){ // 이렇게 하면 틀림.
        //     if(conn[wordIdx][j] == 1){
        //         indegree[j] -- ;
        //         if(indegree[j] == 0){
        //             q.push(j);
        //         }
        //     }
        // }
    }
    
    if(visitCnt != 0){
        impossible = true;
    }
    
    if(impossible){
        cout<<"!";
    }else if(moreThanOne){
        cout<<"?";
    }else{
        cout<<answer;
    }
}