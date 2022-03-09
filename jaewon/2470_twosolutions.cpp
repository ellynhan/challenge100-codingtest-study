#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define boost ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int main(){
    boost;
    int n;
    cin >> n;
    vector<int> solutions; 
    for(int i=0; i<n; i++){
        int s;
        cin >> s;
        solutions.push_back(s);
    }
    sort(solutions.begin(), solutions.end());
    int lower=0, upper=n-1;
    int ansL=0, ansU=n-1;
    int min = 2000000000;
    while(lower<upper){
        int curr = solutions[lower]+solutions[upper];
        if(abs(curr)<abs(min)){
            ansL = lower;
            ansU = upper;
            min = curr;
        }
        if(curr<0){
            lower++;
        }else{
            upper--;
        }
    }
    cout<<solutions[ansL]<<" "<<solutions[ansU];
}
