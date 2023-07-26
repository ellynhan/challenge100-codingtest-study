#include <cstdio>
#include <stack>

using namespace std;

int main(void) {
    int k;
    scanf("%d", &k);

    int answer = 0;
    stack<int> last;
    for (int i = 0; i < k; i++) {
        int n;
        scanf("%d", &n);

        if (n) {
            answer += n;
            last.push(n);
        }
        else {
            answer -= last.top();
            last.pop();
        }

    }

    printf("%d", answer);

    return 0;
}