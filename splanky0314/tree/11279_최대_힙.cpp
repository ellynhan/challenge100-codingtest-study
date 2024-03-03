#include <iostream>
#include <vector>
using namespace std;

vector<int> heap(100001);
int cnt=0;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int pop() {
	if(cnt==0) return 0;

	int result = heap[1];
	
	swap(heap[1], heap[cnt]);
	cnt--;
	
	int parent=1;
	int child = parent*2;
	if(child+1<=cnt) {
		child = (heap[child]>heap[child+1]) ? child : child+1;
	}
	while(child<=cnt && heap[parent]<heap[child]) {
		swap(heap[parent], heap[child]);
		parent = child;
		child = child*2;
		if(child+1<=cnt) {
			child = (heap[child]>heap[child+1]) ? child : child+1;
		}
	}
	return result;
}

void push(int x) {
	heap[++cnt]=x;
	int child = cnt;
	int parent = child/2;
	while(1<child && heap[parent]<heap[child]) {
		swap(heap[parent], heap[child]);
		child = parent;
		parent = child/2;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n, tmp;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp==0) {
			cout << pop() << "\n";
		}
		else {
			push(tmp);
		}
	}
}