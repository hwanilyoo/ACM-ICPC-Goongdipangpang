#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321
int arr[1001];
int dp[1001]; //i�� ���������� �ϴ� ���������� ����
int n;
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		lower_bound(arr, arr + n, arr[i]);
	}
	return 0;
}