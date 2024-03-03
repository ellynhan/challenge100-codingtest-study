//
//  FANMEETING.cpp
//  main
//
//  Created by wi_seong on 1/12/24.
//

/*
 [Input]
 4
 FFFMMM
 MMMFFF
 FFFFF
 FFFFFFFFFF
 FFFFM
 FFFFFMMMMF
 MFMFMFFFMMMFMF
 MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF
 [Output]
 1
 6
 2
 2
 */
// 시간복잡도: O(n ^ lg3)
// 최악시간: 3,000,000
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/FANMEETING

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t;

void normalize(vector<int>& num) { }

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            c[i + j] += a[i] * b[j];
    // normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    if(a.size() < b.size() + k)
        a.resize(b.size() + k);
    for(int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
    // normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < b.size(); i++)
        a[i] -= b[i];
    // normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = int(a.size()); int bn = int(b.size());

    if(an < bn) return karatsuba(b, a);

    if(an == 0 || bn == 0) return vector<int>();

    if(an <= 50) return multiply(a, b);

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(int(b.size()), half));
    vector<int> b1(b.begin() + min<int>(int(b.size()), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0); addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0); subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0); addTo(ret, z1, half); addTo(ret, z2, half * 2);

    return ret;
}

int solve(const string& member, const string& fan) {
    int n = int(member.size()); int m = int(fan.size());
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) a[i] = (member[i] == 'M');
    for(int i = 0; i < m; i++) b[m - i - 1] = (fan[i] == 'M');

    vector<int> c = karatsuba(a, b);
    int allHugs = 0;
    for(int i = n - 1; i < m; i++)
        if(c[i] == 0)
            allHugs++;
    return allHugs;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        string member, fan;
        cin >> member >> fan;
        cout << solve(member, fan) << '\n';
    }

	return 0;
}
