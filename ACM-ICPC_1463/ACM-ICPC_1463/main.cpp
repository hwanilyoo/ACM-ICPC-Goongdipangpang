#include<cstdio>
using namespace std;

#define INF 987654321

int n;
int d[1000002]; //d[i]=i�� 1�θ���������� �ּ�Ƚ��
int main() {
	scanf("%d",&n);
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1; //1�� ��� ���ڿ� ���ؼ� ���� �� �����ϱ�, 2 �Ǵ� 3���� �������°��� �������̴�.
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