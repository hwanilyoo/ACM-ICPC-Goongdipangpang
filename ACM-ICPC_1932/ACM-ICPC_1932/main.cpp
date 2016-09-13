#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321

int n;
int arr[501][501];
int dp[501][501];
int main() {
	scanf("%d",&n);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[1][1] = arr[1][1];
	

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = dp[i - 1][j]+ arr[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1]+ arr[i][j];
			else {
				dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+arr[i][j];
			}
		}
	}

	//printf("%d\n",dp[3][1]);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i])
			max = dp[n][i];
	}

	printf("%d\n",max);


	return 0;
}