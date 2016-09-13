#include<cstdio>

using namespace std;
#define INF 987654321
typedef long long ll;
ll init(ll node, ll start, ll end);
ll sum(ll node, ll start, ll end, ll left, ll right);
void update(ll node, ll start, ll end, ll index, ll diff);
ll N, M, K;
ll arr[20];
ll tree[300];
ll a, b, c;
int main() {
	
	scanf("%lld %lld %lld", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld",&arr[i]);
	}
	
	init(1, 1, N);
	
	ll cnt = M + K;
	
	while (cnt--) {
		
		scanf("%lld %lld %lld",&a,&b,&c);
		if (a == 1) {
			ll ch = c-arr[b] ;
			update(1, 1, N, b, ch);
		}
		else {
			ll res = sum(1, 1, N, b, c);
			printf("%lld\n", res);
		}
	}

	return 0;
}

ll init(ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	ll mid = (start + end) / 2;
	
	tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
	return tree[node];
}

ll sum(ll node, ll start, ll end, ll left, ll right) {
	if (left > end || right < start) // [left,right]와 [start,end]가 겹치지 않는 경우 
		return 0;
	
	if (left <= start && end <= right) { // [left, right]가[start, end]를 완전히 포함하는 경우
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(ll node, ll start, ll end, ll index, ll diff) {
	if (index < start || index > end) {
		return;
	}
	tree[node] = tree[node] + diff;
	ll mid = (start + end) / 2;
	if (start != end) {

		update(node * 2, start, mid, index, diff);
		update(node * 2 + 1, mid + 1, end, index, diff);
	}
}