#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    string id, pw;
    cin >> N >> M;
    map<string, string> m;
    for(int i=0; i<N; i++){
        cin >> id >> pw;
        m.insert({id, pw});
    }
    for(auto i = 0; i<M; i++){
        cin >> id;
        cout << m[id] << '\n';
    }
}