#include<bits/stdc++.h>

using namespace std;

void fibonacci(int n,vector<int> &counting, map<int, int> &zero, map<int, int> &one) {
    switch(n){
    case 0: counting[0]++; break;
    case 1: counting[1]++; break;
    default :
        if(zero.find(n-1) == zero.end()){
            fibonacci(n-1, counting, zero, one);
            zero[n-1] = counting[0];
            one[n-1] = counting[1];
        } else {
            counting[0] += zero[n-1];
            counting[1] += one[n-1];
        }

        if(zero.find(n-2) == zero.end()){
            fibonacci(n-2, counting, zero, one);
            zero[n-2] = counting[0] - zero[n-1];
            one[n-2] = counting[1] - one[n-1];
        } else {
            counting[0] += zero[n-2];
            counting[1] += one[n-2];
        }
    }
}

void output(vector<int> &counting) {
    cout << counting[0] << " " << counting[1] << endl;
}

void data() {
    vector<int> counting;
    map<int, int> zero;
    map<int, int> one;
    int numData, testCase;
    cin >> numData;
    while(numData--) {
        cin >> testCase;
        counting = {0,0};
        fibonacci(testCase, counting, zero, one);
        output(counting);
    }
}

int main() {
    data();
    return 0;
}
