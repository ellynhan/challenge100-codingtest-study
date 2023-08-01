#include <iostream>
#include <vector>
using namespace std;
void fibonacci(int);

int countZero = 0;
int countOne = 0;
vector<int> usedZ(41, -1);
vector<int> usedO(41, -1);

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i < N; i++){
        int tmp; cin >> tmp;
        fibonacci(tmp);
        cout << countZero << " " << countOne << "\n";
        countZero = 0;
        countOne = #include <iostream>
#include <vector>
using namespace std;
void fibonacci(int);

int countZero = 0;
int countOne = 0;
vector<int> usedZ(41, -1);
vector<int> usedO(41, -1);

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    for(int i=0; i < N; i++){
        int tmp; cin >> tmp;
        fibonacci(tmp);
        cout << countZero << " " << countOne << "\n";
        countZero = 0;
        countOne = 0;
    }
}

void fibonacci(int n) {
    if (n == 0) {
        countZero++;
    } else if (n == 1) {
        countOne++;
    } else if (usedZ[n] >= 0) {
        countZero += usedZ[n];
        countOne += usedO[n];
    } else {
        fibonacci(n-1);
        fibonacci(n-2);
        usedZ[n] = countZero;
        usedO[n] = countOne;
    }
}
0;
    }
}

void fibonacci(int n) {
    if (n == 0) {
        countZero++;
    } else if (n == 1) {
        countOne++;
    } else if (usedZ[n] >= 0) {
        countZero += usedZ[n];
        countOne += usedO[n];
    } else {
        fibonacci(n-1);
        fibonacci(n-2);
        usedZ[n] = countZero;
        usedO[n] = countOne;
    }
}
