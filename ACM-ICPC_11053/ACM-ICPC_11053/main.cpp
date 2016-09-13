#include<cstdio>
#include<algorithm>
#define INF 987654321
using namespace std;

int arr[1001];
int dp[1001];
int N;
int main() {
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		scanf("%d",&arr[i]);
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] &&  1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
			}
		}
	}
	sort(dp+1, dp + N+1);
	printf("%d\n",dp[N]);
	return 0;
}