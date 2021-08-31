#include <cstdio>
#include <unordered_set>
#include <cassert>
#include <algorithm>

using namespace std;

int main(void) {
	bool result[21] = {};
	int n;
	scanf("%d", &n);
	char dir[7] = "";
	int argu;
	for (int i = 0; i < n; i++){
		scanf("%s", dir);
		if (dir[0] == 'a' && dir[1] == 'l')
			fill(result+1, result + 21, true);
		else if (dir[0] == 'e') {
			fill(result+1, result + 21, false);
		}
		else {
			scanf("%d", &argu);
			if (dir[0] == 'a')
				result[argu] = true;
			else if (dir[0] == 'r')
				result[argu] = false;
			else if (dir[0] == 'c')
				printf("%d\n", (int)result[argu]);
			else if (dir[0] == 't') {
				result[argu] = !result[argu];
			}
			else
				assert(false);
		}

	}
	return 0;
}