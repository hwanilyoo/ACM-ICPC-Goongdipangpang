/*
��ȭ�� : dp[i]=i��° ��ܿ� �ö� �������� �ִ� ��
dp[i]=arr[i]+arr[i-1] +dp[i-3] // ���� ����� ����� ��, �����ؼ� 3����� ���� �� �����Ƿ�, ������������ ���� ������
dp[i]=arr[i]+dp[i-2] // ��������� �������, ���� ����� ���� �� �����Ƿ�, ���������� ��ܹ��� ���� ������
*/
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[333];
int dp[333];
int main() {
	int T;
	scanf("%d",&T);
	
	for (int i = 1; i <= T; i++){
		scanf("%d",&arr[i]);
	}

	//dp[0] = arr[0];//10;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	//printf("\n\n");
	for (int i = 3; i <= T; i++){
		/* dp[i] = arr[i]+����+��������
		   dp[i] = arr[i]+������
		   ���߿� �ִ밪
		*/
		dp[i] = max((arr[i] + dp[i - 2]), (arr[i] +arr[i-1]+dp[i-3]));
		
		
	}
	//printf("\n");
	printf("%d\n",dp[T]);
	return 0;
}

