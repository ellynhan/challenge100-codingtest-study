#include<stdio.h>
int main() {
	int i, n, m = 0, k, a[11]; scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = n; i > 0; i--) {
		m += k / a[i];
		k %= a[i];
	}
	printf("%d", m);
}
