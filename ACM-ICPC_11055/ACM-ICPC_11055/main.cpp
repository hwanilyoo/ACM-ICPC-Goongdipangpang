#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 987654321
int arr[1001];
int d[1001]; //d[i]=i��° ���� �ϴ� �� �� �ִ� ���� ��
int n;
int main() {
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d",&arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		d[i] = arr[i];
		
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && arr[i] + d[j] > d[i]) {
				d[i] = arr[i] + d[j];
			}
		}
	}
	int res = *max_element(d, d + n);
	printf("%d\n",res);
	return 0;
}