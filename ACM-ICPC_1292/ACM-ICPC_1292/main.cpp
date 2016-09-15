#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define INF 987654321

int arr[1001];

int main() {
	int num1, num2;
	scanf("%d %d",&num1,&num2);
	int cnt = 0;
	int cnt2 = 0;
	
	for (int i = 1; i<=1000; i++) {
		cnt++;
		
		for (int j = 1; j <= i; j++) {
			if (cnt2 == 1000)break;
			cnt2++;
			arr[cnt2] = cnt;
			
		}
		
		
	}
	
	int sum = 0;
	for (int i = num1; i <= num2; i++) {
		sum += arr[i];
	}

	printf("%d\n",sum);
	return 0;
}