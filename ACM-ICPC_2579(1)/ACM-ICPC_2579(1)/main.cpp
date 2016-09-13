/*
점화식 : dp[i]=i번째 계단에 올라 갔을때의 최대 값
dp[i]=arr[i]+arr[i-1] +dp[i-3] // 직전 계단을 밟았을 시, 연속해서 3계단을 밟을 수 없으므로, 전전전까지의 값을 더해줌
dp[i]=arr[i]+dp[i-2] // 전전계단을 밟았을시, 직전 계단을 밟을 수 없으므로, 전전까지의 계단밟은 값을 더해줌
*/

#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321

int n;
int arr[301];
int d[301];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		//int a;
		scanf("%d", &arr[i]);
		//arr[i] = a;

	}

	d[1] = arr[1];
	d[2] = arr[1] + arr[2];
	
	for (int i = 3; i <= n; i++) {
		//d[i] = max(d[i - 3] + arr[i - 1], d[n - 2]) + arr[i];
		d[i] = max((d[i - 3] + arr[i - 1] + arr[i]), (d[i - 2] + arr[i])) ;
	
	//dp[i] = max((arr[i] + dp[i - 2]), (arr[i] +arr[i-1]+dp[i-3]));
	}
	printf("%d\n", d[n]);
	return 0;
}
v
