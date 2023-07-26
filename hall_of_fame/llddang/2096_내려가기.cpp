#include <iostream>
using namespace std;

int N;
int arr[100000][3];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
    for(int j=0; j<3; j++) cin >> arr[i][j];

    int maxA=0, maxB=0, maxC=0, minA=0, minB=0, minC=0;
    int tmpA, tmpB, tmpC;
    for(int i=N-1; i>=0; i--){
        tmpA = arr[i][0] + max(maxA, maxB);
        tmpB = arr[i][1] + max(maxA, max(maxB, maxC));
        tmpC = arr[i][2] + max(maxB, maxC);
        maxA = tmpA; maxB = tmpB; maxC = tmpC;

        tmpA = arr[i][0] + min(minA, minB);
        tmpB = arr[i][1] + min(minA, min(minB, minC));
        tmpC = arr[i][2] + min(minB, minC);
        minA = tmpA; minB = tmpB; minC = tmpC;
    }

    int answerMax = max(maxA, max(maxB, maxC));
    int answerMin = min(minA, min(minB, minC));

    cout << answerMax << " " << answerMin;
}
