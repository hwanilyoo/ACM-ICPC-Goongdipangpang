#include<cstdio>
#include<vector>

typedef long long ll;
using namespace std;
void update(ll idx);
ll sum(ll left, ll right);
#define INF 987654321
vector<long long> myV;
ll N,S,tmp,h;
int main() {

	
	
	scanf("%lld %lld",&N,&S);
	tmp = 1,h=0;

	while (N>tmp) {
		tmp = tmp * 2;
		//tmp++;
		h++;
	}

	myV.resize(tmp * 2, 0); 
	
	for (int i = 0; i < N; i++) {
		scanf("%lld",&myV[tmp+i]);
		update(tmp + i);
	}

	
		ll a, b, c;
		scanf("%lld %lld %lld",&a,&b,&c);

		if (a == 2) {
			ll res = sum(tmp+b-1, tmp+c-1);
			printf("%lld\n",res);
		}
		else { //b번째 수를 C로바꿔
			
			myV[tmp + b - 1] = c; //1 3 6 8+3-1=6 // 3번쨰 수를 6으로
			
			update(tmp + b - 1);
			
		}
	return 0;
}

void update(ll idx) { //10
	if (idx == 1)return;
	if (idx % 2 == 1)idx -= 1;
	
	myV[idx / 2] = myV[idx] + myV[idx + 1];
	
	update(idx / 2);
}

ll sum(ll left, ll right) {
	ll sum = 0;
	
	while (left < right) { //2,5
		
		if (left % 2 == 1) {
			sum += myV[left];
			left = (left + 1) / 2;
		}
		else {
			left /= 2;
		}

		if (right % 2 == 0) {
			sum += myV[right];
			right = (right - 1) / 2;
		}
		else {
			right /= 2;
		}
	}
	if (left == right) {
		sum += myV[left];
	}

	return sum;
}