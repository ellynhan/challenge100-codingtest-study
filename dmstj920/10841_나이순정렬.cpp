#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Member{
    int age;
    char name[101];
    int order;
};

bool cmp(const Member& a, const Member& b){
    if(a.age == b.age){
        return (a.order < b.order);
    }

    return a.age < b.age;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, i;
    cin >> num;

    vector<Member> v;
    Member member;

    for(i=0; i<num; i++){
        cin >> member.age >> member.name;
        member.order = i;

        v.push_back(member);
    }

    sort(v.begin(), v.end(), cmp);

    for(i=0; i<num; i++){
        cout << v[i].age << " " << v[i].name << "\n";
    }


    return 0;
}
