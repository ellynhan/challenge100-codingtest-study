#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int korean;
    int english;
    int math;
};

bool cmp(const Student& a, const Student& b){
    if(a.korean == b.korean){
        if(a.english == b.english){
            if(a.math == b.math){
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}

int main()
{
    int num, i;
    cin >> num;

    vector<Student> v;
    Student student;

    for(i=0; i<num; i++){
        cin >> student.name >> student.korean >> student.english >> student.math;

        v.push_back(student);
    }

    sort(v.begin(), v.end(), cmp);

    for(i=0; i<num; i++){
        cout << v[i].name << '\n';
    }

    return 0;
}
