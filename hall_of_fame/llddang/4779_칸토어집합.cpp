#include <iostream>
#include <cmath>
using namespace std;

void printSpace(int n){
    while(n--){
        cout << " ";
    }
}

void printLine(int N){
    if(N == 1) cout << "-";
    else {
        printLine(N/3);
        printSpace(N/3);
        printLine(N/3);
    }
}

int main()
{
    int N;
    while(!(cin >> N).eof()){
        printLine(pow(3, N));
        cout << "\n";
    }
}
