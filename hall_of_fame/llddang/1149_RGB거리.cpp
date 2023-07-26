#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct color{
    color(int r, int g, int b):
        red{r}, green{g}, blue{b}{}
    int red;
    int green;
    int blue;
};

vector<color> store;
int db[1001][3];

int calc(string choose, int curr, int T){
    if(curr == T) return 0;

    if(choose == "red") {
        if(db[curr][0] != -1) return db[curr][0];

        int case1 = calc("green", curr+1, T) + store[curr].green;
        int case2 = calc("blue" , curr+1, T) + store[curr].blue;

        int tmp = min(case1, case2);
        db[curr][0] = tmp;

        return tmp;

    } else if(choose == "green") {
        if(db[curr][1] != -1) return db[curr][1];

        int case1 = calc("red" , curr+1, T) + store[curr].red;
        int case2 = calc("blue", curr+1, T) + store[curr].blue;

        int tmp = min(case1, case2);
        db[curr][1] = tmp;

        return tmp;

    } else {
        if(db[curr][2] != -1) return db[curr][2];

        int case1 = calc("green", curr+1, T) + store[curr].green;
        int case2 = calc("red"  , curr+1, T) + store[curr].red;

        int tmp = min(case1, case2);
        db[curr][2] = tmp;

        return tmp;
    }
}

int main(){
    memset(db, -1, sizeof(db));

    int T; cin >> T;
    for(int i=0; i<T; i++){
        int r, g, b; cin >> r >> g >> b;
        store.push_back(color(r, g, b));
    }

    int case1 = calc("red"  , 1, T) + store[0].red;
    int case2 = calc("green", 1, T) + store[0].green;
    int case3 = calc("blue" , 1, T) + store[0].blue;

    int result = min(case1, case2);
    result = min(result, case3);

    cout << result;
}
