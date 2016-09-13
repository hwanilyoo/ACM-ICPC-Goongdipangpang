#include<cstdio>
using namespace std;

#define INF 987654321

int n;
int d[1000002]; //d[i]=i를 1로만들었을때의 최소횟수
int main() {
	scanf("%d",&n);
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1; //1은 모든 숫자에 대해서 뺴줄 수 있으니깐, 2 또는 3으로 나눠지는것은 한정적이다.
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	printf("%d\n",d[n]);
	return 0;
}