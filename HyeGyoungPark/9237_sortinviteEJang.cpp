#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n,needlong,day=0;

    cin >> n;

    int *tree = new int[n];
    int *period = new int[n];
    for(int i=0; i<n; i++){
        scanf("%d",&tree[i]);
    }

    sort(tree,tree+n,greater<>());

    for(int i=0; i<n; i++){
        period[i] = tree[i]+i;
    }

    sort(period, period+n,greater<>());

    cout << period[0] +2;

    delete[] tree;
    delete[] period;

    return 0;
}
