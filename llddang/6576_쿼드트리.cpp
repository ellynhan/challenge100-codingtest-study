#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int arr[513][513];
int N;
string color;

void fillColor(int n, int idx, int jdx){
    int i, j;
    if(color[0] == 'B' || color[0] == 'W'){
        int tmp = color[0] == 'B' ? 1 : 0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                arr[idx + i][jdx + j] = tmp;
            }
        }
        color = color.substr(1);
    } else {
        color = color.substr(1);
        int half = n/2;
        fillColor(half, idx, jdx);
        fillColor(half, idx, jdx + half);
        fillColor(half, idx+half, jdx);
        fillColor(half, idx+half, jdx+half);
    }
}

void printStart(){
    cout << "#define quadtree_width " << N << "\n";
    cout << "#define quadtree_height " << N << "\n";
    cout << "static char quadtree_bits[] = {" << "\n";
}

void printContent(){
    int i, j, k;
    for(i=0; i<N; i++){
        for(j=0; j<N; j+=8){
            int tmp = 0;
            for(k=0; k<8; k++){
                tmp += pow(2, k) * arr[i][j+k];
            }
            if(tmp < 16)
                cout << "0x0" << hex << tmp << ",";
            else
                cout << "0x" << hex << tmp << ",";
        }
        cout << "\n";
    }
}

void printEnd(){
    cout << "};";
}

int main(){
    cin >> N >> color;
    fillColor(N, 0, 0);
    
    printStart();
    printContent();
    printEnd();
    
    return 0;
}
