#include<cstdio>
using namespace std;
#define INF 987654321
int dp[1000021];
int main() {
	int n;
	dp[1] = 0;
	scanf("%d",&n);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
			dp[i] = dp[i / 2] + 1;
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
			dp[i] = dp[i / 3] + 1;
	}
	printf("%d\n",dp[n]);
	return 0;
}