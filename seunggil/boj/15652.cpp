#include <iostream>
#include <list>
using namespace std;

int n, m;

void printSet(list<int> data, int index) {
	for (int i = index; i <= n; i++) {
		data.push_back(i);
		if (data.size() == m) {
			for (int iter : data)
				printf("%d ",iter);
			printf("\n");
		}else
			printSet(data, i);
		data.pop_back();
	}
}

int main(void) {
	cin >> n >> m;

	printSet(list<int>(),1);
	
	return 0;
}