#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n,age;
    string name;
    vector <string> namelist;
    vector <pair<int, int>> join;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> age >> name;
        join.push_back({age,i});
        namelist.push_back(name);
    }

    sort(join.begin(),join.end());

    for(int i=0; i<n; i++){
        cout << join[i].first <<" " << namelist[join[i].second] <<"\n";
    }

    return 0;
}
