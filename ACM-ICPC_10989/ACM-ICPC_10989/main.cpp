#include<cstdio>
using namespace std;
#define INF 987654321

int arr[10001];
int N;
int main() {
	scanf("%d",&N);

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d",&a);
		arr[a] += 1;

	}
	// 3 2 1 2 3 
	for (int i = 1; i < 10001; i++) {
		for (int j = 1; j <= arr[i]; j++) { //arr[1]=3;
			printf("%d\n",i);
		}
		

	}
	return 0;
}