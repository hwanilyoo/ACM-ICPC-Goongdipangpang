/*
��ȭ�� : dp[i]=i��° ��ܿ� �ö� �������� �ִ� ��
dp[i]=arr[i]+arr[i-1] +dp[i-3] // ���� ����� ����� ��, �����ؼ� 3����� ���� �� �����Ƿ�, ������������ ���� ������
dp[i]=arr[i]+dp[i-2] // ��������� �������, ���� ����� ���� �� �����Ƿ�, ���������� ��ܹ��� ���� ������
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
