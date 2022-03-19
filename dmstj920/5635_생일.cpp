#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct People{
    string name;
    int day;
    int month;
    int year;
};

bool cmp(People &a, People &b){
    if(a.year == b.year){
        if(a.month == b.month){
            return a.day < b.day;
        }

        return a.month < b.month;
    }

    return a.year < b.year;
}

int main()
{
    People people;
    vector<People> v;

    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        cin >> people.name >> people.day >> people.month >> people.year;

        v.push_back(people);
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[v.size()-1].name << "\n";
    cout << v[0].name;
}
