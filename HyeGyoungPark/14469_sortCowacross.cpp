#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> cow;

int main(void){
    int n,x,y,now=0;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y;
        cow.push_back(pair<int,int>(x,y));
    }

    sort(cow.begin(), cow.end());

    for(int i=0; i<n; i++){
        if(cow[i].first < now) now += cow[i].second;
        else now = cow[i].first + cow[i].second;
    }

    cout << now;

    return 0;
}
