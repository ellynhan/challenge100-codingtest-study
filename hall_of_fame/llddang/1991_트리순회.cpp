#include <iostream>
using namespace std;

int N;
int n[26][2];
string str[3] = {"", "", ""};

void dfs(int i){
    str[0] += ('A' + i);
    if(n[i][0] != -1) dfs(n[i][0]);
    str[1] += ('A' + i);
    if(n[i][1] != -1) dfs(n[i][1]);
    str[2] += ('A' + i);
}
int main(){
    cin >> N;
    char a, b, c;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        int idx = a - 'A';
        if(b != '.') n[idx][0] = b - 'A';
        else  n[idx][0] = -1;
        if(c != '.') n[idx][1] = c - 'A';
        else  n[idx][1] = -1;
    }

    dfs(0);

    for(int i=0; i<3; i++)
        cout << str[i] << "\n";
}
