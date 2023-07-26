#include <iostream>
using namespace std;

int main(){
    int N, kim, yim;
    cin >> N >> kim >> yim;
    int round = 0;
    
    kim--; yim--;
    
    while( kim != yim ){
        kim /= 2;
        yim /= 2;
        round++;
    }
    cout << round;
    return 0;
}
