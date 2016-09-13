/*2번 BFS를 돌린다. 임의의 정점에서 시작하는데 맨 처음 정점에서 돌리는 결과로, 그 정점과 가장 멀리 있는 정점을 알아낸다.
알아낸 정점으로 다시 BFS를 돌리면 트리의 최대 거리(지름)을 알 수 있다.*/

#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define INF 987654321
vector<pair<int, int> > adj[10]; 
bool check[100001];
int degree = 0;
int n;

pair<int, int> bfs(int now) {
	queue<pair<int,int> > myQ;
	check[now] = true;
	myQ.push(make_pair(now, 0));
	
	pair<int, int >a(0, -1); //비교해서 갱신해주기위해서
	
	while (!myQ.empty()) {
		pair<int, int> myP = myQ.front(); myQ.pop();
		if (myP.second > a.second)a = myP; //지금까지온게 나보다 길면 갱신
		
		for (int i = 0; i < adj[myP.first].size(); i++) {
			if (check[adj[myP.first][i].first]==false) {
				pair<int, int> temp;
				temp.first = adj[myP.first][i].first;
				temp.second = myP.second + adj[myP.first][i].second; //이전 weight(누적)와 현재 연결된 정점의 weight를 합쳐서 큐에 넣어준다.
				check[adj[myP.first][i].first] = true;
				myQ.push(temp);
			}
		}
	}
	return a;
}



int main() {
	
	
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d",&a);
		for (;;) {
			scanf("%d",&b);
			if (b == -1)break;
			scanf("%d",&c);
			adj[a].push_back(make_pair(b, c));
			
		}
	}
	
	pair<int,int> aa = bfs(1); //아무점에서 돌리고, 제일 긴 정점에 도착!
	memset(check, 0, sizeof(check));
	pair<int, int> res = bfs(aa.first); // 도착한거를 다시 bfs로 돌려서 도착하는 곳이 제일 끝!
	printf("%d\n",res.second);
	return 0;
}

