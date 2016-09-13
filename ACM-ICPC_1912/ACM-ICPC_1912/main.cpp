#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321
int n;
int arr[100001];
int dp[100001];
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		if (i == 1)continue;
		if (dp[i] < dp[i - 1] + arr[i])
			dp[i] = dp[i - 1] + arr[i];
	}
	sort(dp + 1, dp + n + 1);
	printf("%d\n",dp[n]);
	return 0;
}