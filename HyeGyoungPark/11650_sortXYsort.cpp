#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> dots;

int main(void){
    int n,x,y;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        dots.push_back(pair<int,int>(x,y));
    }

    sort(dots.begin(), dots.end());

    for(int i=0; i<n; i++){
        cout << dots[i].first << " " << dots[i].second << "\n";
    }

    return 0;
}
