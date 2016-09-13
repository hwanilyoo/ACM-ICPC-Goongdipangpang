#include<cstdio>
#include<vector>
using namespace std;
# define INF 987654321
vector<int> myV;
vector<int> L;
vector<int> Tree;
void update(int i, int num);
int sum(int i);
int main() {

	int N,M;
	scanf("%d",&N);
	myV.resize(N + 1, 0);
	L.resize(N + 1, 0);
	Tree.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		scanf("%d",&myV[i]);
		update(i, myV[i]);
	}
	scanf("%d",&M);
	while (M--) {
		int a, b;
		scanf("%d %d",&a,&b);
		int sum1 = sum(a-1);
		int sum2 = sum(b);
		int res = sum2 - sum1;
		printf("%d\n",res);


	}
	
}

void update(int i, int num) {

	while (i < Tree.size()) {
		Tree[i] += num;
		i += (i&-i);
	}
}

int sum(int i) {
	int res=0;
	while (i > 0) {
		res += Tree[i];
		i -= (i&-i);
	}
	return res;
}