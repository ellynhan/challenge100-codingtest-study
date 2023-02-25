#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Country {
public:
    int num;
    int gold;
    int silver;
    int bronze;

    Country() {}
    Country(int num, int a, int b, int c) : num(num), gold(a), silver(b), bronze(c) {}
};

int N;
int target;
vector<Country> countries;

void input() {
    cin >> N >> target;
}

bool compare(Country &a, Country &b) {
    if (a.gold == b.gold) {
        if (a.silver == b.silver) {
            if (a.bronze == b.bronze) {
                return false;
            } else {
                return a.bronze > b.bronze;
            }
        } else {
            return a.silver > b.silver;
        }
    } else {
        return a.gold > b.gold;
    }
    return false;
}

bool same_rank(Country &a, Country &b) {
    return a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze;
}

int answer() {
    int num, a, b, c;
    for (int i = 1; i <= N; i++) {
        cin >> num >> a >> b >> c;
        countries.push_back(Country(num, a, b, c));
    }
    sort(countries.begin(), countries.end(), compare);
    int rank = 1;
    int add_rank = 1;
    for (int i = 0; i < N; i++) {
        Country c = countries[i];
        if (c.num == target) {
            return rank;
        }
        if (!same_rank(countries[i], countries[i+1])) {
            rank += add_rank;
            add_rank = 1;
        } else {
            add_rank++;
        }
    }
    return -1;
}

int main() {
    input();
    int result = answer();
    cout << result << endl;

    return 0;
}