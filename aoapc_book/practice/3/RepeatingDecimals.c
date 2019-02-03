#include<stdio.h>
#include<string.h>

const int MYDD = 1103+1e4;

int main() {
	int quotient[MYDD];
	int remainder[MYDD];
	int u[MYDD];
	int n, m, t;

	while(scanf("%d %d", &n, &m) != EOF) {
		t = n;/*3000以内*/
		memset(quotient, 0, sizeof(quotient));
		memset(u, 0, sizeof(u));
		int cnt = 0;
		quotient[cnt++] = n/m;
		n %= m;
		while(!u[n] && n) {
			u[n] = cnt;
			remainder[cnt] = n;
			quotient[cnt++] = 10*n/m;
			n = 10*n%m;
		}

		printf("%d/%d = %d.", t, m, quotient[0]);
		for (int i = 1 ; i < cnt && i <= 50 ; i++) {
			if (n && remainder[i] == n) printf("(");
			/*存在循环节->开始存在余数相同的位置*/
			printf("%d",quotient[i]);
		}
		if (!n) printf("(0");
		if (cnt > 50) printf("...");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",!n? 1:cnt-u[n]);

	}
	return 0;
}
