#include <bits/stdc++.h>
using namespace std;

struct Person {
    int age;
    string name;
};

bool compare(Person a, Person b) {
    if (a.age != b.age) {
        return a.age < b.age;
    } 
}

Person member[100000]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> member[i].age >> member[i].name;
    }
    
    stable_sort(member, member + N, compare);

    for (int i = 0; i < N; i++) {
        cout << member[i].age << "\n" << member[i].name << "\n";
    }

}