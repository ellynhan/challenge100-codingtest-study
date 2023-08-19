//1120 ~ 1148

#include <iostream>
using namespace std;

int paper[128][128];
int ans[2];

void check(int sy, int sx, int n){
	if(n == 0){
		cout<<"is possible?";
	}
	int color = paper[sy][sx];
	for(int i=sy; i<sy+n; i++){
		for(int j=sx; j<sx+n; j++){
			if(paper[i][j] != color){
				check(sy, sx, n/2);
				check(sy, sx+n/2, n/2);
				check(sy+n/2, sx, n/2);
				check(sy+n/2, sx+n/2, n/2);
				color = -1;
				j = sx+n;
				i = sy+n;
			}
		}
	}
	if(color != -1){
		ans[color]+=1;

	}

}


int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> paper[i][j];

		}
	}
	check(0,0,N);
	cout<<ans[0]<<'\n'<<ans[1];
}