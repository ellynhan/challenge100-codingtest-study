#include <iostream>
using namespace std;

long long N, B;
int arr[5][5];
int storeArr[40][5][5];
int result[2][5][5];
bool flag = false;

int main(){
    cin >> N >> B;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> arr[i][j];

    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) storeArr[1][i][j] = arr[i][j] % 1000;

    long long sum, cnt=1, idx=2;
    while(cnt * 2 < B){
        for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            sum = 0;
            for(int k=0; k<N; k++) sum += storeArr[idx-1][i][k] * storeArr[idx-1][k][j];
            storeArr[idx][i][j] = sum % 1000;
        }
        idx++;
        cnt *= 2;
    }
    B -= cnt; idx--;
    for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) result[flag][i][j] = storeArr[idx][i][j];
    
    int k;
    while(B > 0){
        k = B / cnt;
        while(k--){
            for(int i=0; i<N; i++)
            for(int j=0; j<N; j++){
                sum = 0;
                for(int k=0; k<N; k++) sum += result[flag][i][k] * storeArr[idx][k][j];
                result[!flag][i][j] = sum % 1000;
            }
            flag = !flag;
        }
        B %= cnt;
        cnt /= 2;
        idx--;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout << result[flag][i][j] << " ";
        cout << "\n";
    }
}
