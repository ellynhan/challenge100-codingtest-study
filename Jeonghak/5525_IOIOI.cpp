#include<iostream>
#include<string>

using namespace std;
int N, M, k, ans=0;
string S, IOIOI = "I";

void Input(){
    cin >> N >> M >> S;
}

int main(){
    Input();
    for(int i=0; i<M; i++){
        if(S[i] == 'I'){
            cout << i << endl;
            while (S[i + 1] == 'O' && S[i + 2] == 'I'){
                k++;
                i += 2;
                if (k == N){
                    ans++;
                    k--;    // 겹쳐진 IOI를 찾기 위해서
                }
            }
            k = 0;
        }
    }
    cout << ans;
}