#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321


int dp[100010]; //dp[i]==i를 마지막으로 더하는 연속합이 저장되어 있는 배열
int arr[100010];
int n;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
	}
	/*
		10
		
		10 -4 3 1 5 6 -35 12 21 -1
	*/
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		if (i == 1)continue;
		if (dp[i-1] + arr[i] > arr[i])
			dp[i] = dp[i-1] + arr[i];
		else
			dp[i] = arr[i];
		
	}

	printf("%d\n", *max_element(dp + 1, dp + n + 1));
	return 0;
}