#include <iostream>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define maxNum 1001
using namespace std;

int house[1000][3];
int dpRed[1000][3];
int dpGreen[1000][3]; 
int dpBlue[1000][3]; 

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> house[i][0];
        cin >> house[i][1];
        cin >> house[i][2];
    }  
    
    dpRed[0][0] = house[0][0];
    dpRed[0][1] = maxNum;
    dpRed[0][2] = maxNum;
    dpGreen[0][0] = maxNum;
    dpGreen[0][1] = house[0][1];
    dpGreen[0][2] = maxNum;
    dpBlue[0][0] = maxNum;
    dpBlue[0][1] = maxNum;
    dpBlue[0][2] = house[0][2];

    for(int i=1; i<n; i++){
        dpRed[i][0] = min(dpRed[i-1][1], dpRed[i-1][2])+house[i][0];
        dpRed[i][1] = min(dpRed[i-1][0], dpRed[i-1][2])+house[i][1];
        dpRed[i][2] = min(dpRed[i-1][0], dpRed[i-1][1])+house[i][2];
        dpGreen[i][0] = min(dpGreen[i-1][1], dpGreen[i-1][2])+house[i][0];
        dpGreen[i][1] = min(dpGreen[i-1][0], dpGreen[i-1][2])+house[i][1];
        dpGreen[i][2] = min(dpGreen[i-1][0], dpGreen[i-1][1])+house[i][2];
        dpBlue[i][0] = min(dpBlue[i-1][1], dpBlue[i-1][2])+house[i][0];
        dpBlue[i][1] = min(dpBlue[i-1][0], dpBlue[i-1][2])+house[i][1];
        dpBlue[i][2] = min(dpBlue[i-1][0], dpBlue[i-1][1])+house[i][2];
    }
    int redMin = min(dpRed[n-1][1],dpRed[n-1][2]);
    int greenMin = min(dpGreen[n-1][0],dpGreen[n-1][2]);
    int blueMin = min(dpBlue[n-1][0],dpBlue[n-1][1]);
    cout<<min(redMin, min(greenMin, blueMin));
}   