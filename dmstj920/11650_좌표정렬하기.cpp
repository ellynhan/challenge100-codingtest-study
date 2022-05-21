#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Coordinate{
    int x;
    int y;
};

bool cmp(Coordinate& a, Coordinate& b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    int num, i;
    Coordinate coordinate;
    vector<Coordinate> v;

    cin >> num;

    for(i=0; i<num; i++){
        cin >> coordinate.x >> coordinate.y;
        v.push_back(coordinate);
    }

    sort(v.begin(), v.end(), cmp);

    for(i=0; i<num; i++)
        cout << v[i].x << " " << v[i].y << "\n";

    return 0;
}
