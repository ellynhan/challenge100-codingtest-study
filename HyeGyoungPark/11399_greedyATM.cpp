#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n, need=0, ans=0;

    cin >> n;

    int* line = new int[n];

    for (int i=0; i<n; i++){
        cin >> line[i];
    }

    sort(line, line+n);


    for(int i=0; i<n; i++){
        need += line[i];
        ans += need;
    }

    cout << ans;

    delete[] line;


    return 0;
}
