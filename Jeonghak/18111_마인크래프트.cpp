#include<iostream>

using namespace std;
int N, M, B, minBlock, maxBlock;
int map[501][501];

void Input(){
    cin >> N >> M >> B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
}

int main()
{
    Input();
    int result=100000000, height=0;
    for(int k=0; k<=256; k++){
        int currT = 0;
        int inven = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int gap = map[i][j] - k;
                if(gap < 0) {
                    currT += -gap;
                    inven -= -gap;
                }
                else if(gap > 0) {
                    currT += gap*2;
                    inven += gap;
                }; 
            }
        }
        if(B + inven >= 0){ 
            if(result >= currT) {
                height = k;
                result = currT;
            }
        }
    }
    cout << result << ' ' << height;
}   
