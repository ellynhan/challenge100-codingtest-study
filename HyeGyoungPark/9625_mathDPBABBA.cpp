#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector <int> a;
    vector <int> b;

    a.push_back(1);
    b.push_back(0);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        a.push_back(b[i]);
        b.push_back(a[i]+b[i]);
    }

    cout << a.at(n) << " " << b.at(n);

    return 0;
}
