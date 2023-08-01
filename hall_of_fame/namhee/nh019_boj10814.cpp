#include <iostream>
#include <algorithm>

using namespace std;

struct member {
	int age;
	string name;
};
bool comp(member a, member b);
member mem [100001];

int main() {
	// 1. INPUT DATA
	int N;
	cin >> N;
	
	for (int i=0; i<N; i++)
		cin >> mem[i].age >> mem[i].name;
	
	// 2. SORT
	stable_sort(mem, mem+N, comp);
	
	// 3. OUTPUT DATA
	for (int i=0; i<N; i++)
		cout << mem[i].age << ' ' << mem[i].name << '\n';
}	

// order of age. if same age, order of registeration
bool comp(member a, member b) {
	return a.age < b.age;
}
