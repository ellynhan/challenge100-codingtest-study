#include<bits/stdc++.h>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int func(const string& a, const string& b) {
  int aleng=a.length(), bleng=b.length();
	vector<int> fail(bleng, 0);

	for(int i=1, j=0; i<bleng; i++) {
		while(b[i]!=b[j]&&j>0) {
      j=fail[j-1];
    }

		if(b[i]==b[j]) {
      fail[i]=++j;
    }
	}

	for(int i=1, j=0; i<aleng; i++) {
		while(a[i]!=b[j]&&j>0){
      j=fail[j-1];
    }

		if(a[i]==b[j]) {
			if(j==bleng-1) {
        return i-j;
      } else {
        j++;
      }
		}
	}
  return 0;
}

int main() {
  ioboost;

  string str;

	for(;;) {
		cin>>str;
    
	if(str==".") {
      break;
    }

		int n=func(str+str, str);
		cout<<str.length()/n<<"\n";
	}
	return 0;
}