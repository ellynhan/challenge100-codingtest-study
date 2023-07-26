#include <iostream>
using namespace std;
//0240~310
int board[1025][1025];
int row[1025][1025];
int main(){
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int prev = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
            row[i][j] = board[i][j]+prev;
            prev = row[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int sum = 0;
        int row1,row2,col1,col2;
        cin >> row1 >> col1 >> row2 >> col2;
        for(int j=row1; j<=row2; j++){
            if(col1==1){
                sum += row[j][col2]-row[j-1][n];
            }else{
                sum += row[j][col2]-row[j][col1-1];
            }
            
        }
        cout<<sum<<'\n';
    }
}
