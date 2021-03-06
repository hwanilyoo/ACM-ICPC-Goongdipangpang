#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321

int arr[1001];
int dp[1001]; //dp[i] == i를 마지막으로 하는 부분수열의 길이
int N;
int main() {
	scanf("%d",&N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	/* 
	10 20 10 30 20 50
	1  2   1 3  2  4

	*/
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i] ) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	printf("%d\n", *max_element(dp+1,dp+N+1));
	return 0;

}