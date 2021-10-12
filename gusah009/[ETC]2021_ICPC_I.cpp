#include <iostream> 
#include <bits/stdc++.h> 

/*
    단축키 

    ctrl+shft+B     : compile / execute 
    F5              : mingw/bin/gdb.exe debugging 
*/

//team066
//pyy7yp6r 

using namespace std; 

typedef struct person {
    int num;
    int p;
    int q;
    int r;
    int mul;
    int add;
} Person;

int N;
Person people[101];

bool cmp(const Person& a, const Person& b) {
    if (a.mul > b.mul) {
        return true;
    } else if (a.mul < b.mul) {
        return false;
    } else {
        if (a.add > b.add) {
            return true;
        } else if (a.add < b.add) {
            return false;
        } else {
            return a.num > b.num;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> N;

    for (int i=0; i<N; ++i) {
        cin >> people[i].num >> people[i].p >> people[i].q >> people[i].r;
        people[i].mul = people[i].p * people[i].q * people[i].r;
        people[i].add = people[i].p + people[i].q + people[i].r;
    }

    sort(people, people+N, cmp);

    for (int i=N-1; i>N-4; --i) {
        cout << people[i].num << " ";
    }
    return 0; 
}