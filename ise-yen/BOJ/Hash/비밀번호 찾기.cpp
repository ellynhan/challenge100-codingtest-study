#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N{}, M{};
	cin >> N >> M;
	unordered_map<string, string> um;
	for (int i = 0; i < N; i++) {
		string site{}, pswr{};
		cin >> site >> pswr;
		um.insert({ site, pswr });
	}
	for (int i = 0; i < M; i++) {
		string site{};
		cin >> site;
		cout << um[site] << "\n";
	}
	return 0;
}
