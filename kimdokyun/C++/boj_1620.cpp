#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string>
using namespace std;

int main() {
	map<string,int> nameDic;
	map<int,string> numDic;
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++) {
		char arr[30];
		scanf(" %s",arr);
		string name = arr;
		nameDic.insert({name,i});
		numDic.insert({i,name});
	}
	for(int i=0;i<M;i++) {
		char arr[30];
		scanf(" %s",arr);
		string quiz = arr;
		if(quiz[0]>='0' && quiz[0]<='9') {
			printf("%s\n",numDic.find(stoi(quiz))->second.c_str() );
		} else {
			printf("%d\n",nameDic.find(quiz)->second);
		}
	}
}
