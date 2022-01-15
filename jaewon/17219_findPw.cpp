#include <iostream>
#include <map>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    ioboost;
    int n, m;
    cin >> n >> m;
    map<string, string> M;
    
    for(int i=0; i<n; i++){
        string address, pw;
        cin >> address >> pw;
        M[address] = pw;
    }

    for(int i=0; i<m; i++){
        string address;
        cin >> address;
        cout<<M[address]<<'\n';
    }
}
