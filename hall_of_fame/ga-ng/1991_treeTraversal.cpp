#include <iostream>

using namespace std;

int arr[50][2];

void preorder (int k) {
    if (k == -1) return;
    cout << (char)(k+'A');
    preorder(arr[k][0]);
    preorder(arr[k][1]);
}

void inorder (int k) {
    if (k == -1) return;
    inorder(arr[k][0]);
    cout << (char)(k+'A');
    inorder(arr[k][1]);
}

void postorder (int k) {
    if (k == -1) return;
    postorder(arr[k][0]);
    postorder(arr[k][1]);
    cout << (char)(k+'A');
}

int main() {
    int n;
    cin >> n;
    
for (int i=0; i<n; i++) {
		char x, y, z;
		cin >> x >> y >> z;		// 알파벳 입력
		x = x-'A';		// 문자 -> 숫자 변환
		if (y == '.') {		// 입력이 .이면 그 자리에 -1 대입
			arr[x][0] = -1;
		}
		else {
			arr[x][0] = y-'A';
		}
		if(z == '.') {
			arr[x][1] = -1;
		}
		else {
			arr[x][1] = z-'A';
		}
	}

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

}