/*마주치면 뒤돌아간다고 하지만, 자세히 살펴보며, 뒤돌아가나, 계속앞으로가나 똑같은 걸 알 수 있다.*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define INF 987654321

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		vector<int> myV;
		vector<int> myV2;
		int l, n, res = -1, res2 =-1;
		
		scanf("%d %d", &l, &n);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);

			if (l - a > a - 0) { //8 2
				myV.push_back(l - a);	//2,6,7
				myV2.push_back(a - 0);	//2,6,7
			}
			else {
				myV.push_back(a - 0);	//4 6
				myV2.push_back(l - a);	//2,6,7
			}
		}
	
		for (int i = 0; i < n; i++) {
			if (res < myV[i]) {
				res = myV[i];
			}

			if (res2 < myV2[i]) {
				res2 = myV2[i];
			}
		}
		printf("%d %d\n",res2,res);
	}



	return 0;
}